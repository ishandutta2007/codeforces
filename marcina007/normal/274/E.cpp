#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#include<stack>
#include<bitset>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define ABS(a) ((a)>0?(a):(-a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef vector<int> VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 400007

P tran(int x,int y){return P(MAXN/2+x+y,MAXN/2+x-y);}
int n,m,k,c,x,y;
P pocz;
string dirp;
set<P> S;
map<PP, int> vis;
vector<int> v[2][MAXN];
vector<P> odc[2][MAXN];
LL res;

void newdir(bool left, bool right) {
    if(!left && right) k = (k+1)%4;
    else if(left && !right) k = (k+3)%4;
    else k=(k+2)%4;
}

void move() {
//    cout << "M " << x-MAXN/2 << " " << y-MAXN/2 << " " << k << endl;
    if(k == 0) {x = *lower_bound(ALL(v[1][y]), x+1) - 1; newdir(S.count(P(x,y+1)), S.count(P(x,y-1)));}
    else if(k == 1) {y = *lower_bound(ALL(v[0][x]), y+1) - 1; newdir(S.count(P(x-1,y)), S.count(P(x+1,y)));}
    else if(k == 2) {x = (*--lower_bound(ALL(v[1][y]), x)) + 1; newdir(S.count(P(x,y-1)), S.count(P(x,y+1)));}
    else if(k == 3) {y = (*--lower_bound(ALL(v[0][x]), y)) + 1; newdir(S.count(P(x+1,y)), S.count(P(x-1,y)));}
//    cout << "W " << x-MAXN/2 << " " << y-MAXN/2 << " " << k << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m >> k;
    FOR(i,0,n+1) S.insert(tran(i,0)), S.insert(tran(i,m+1));
    FOR(i,0,m+1) S.insert(tran(0,i)), S.insert(tran(n+1,i));
    while(k--){
        cin >> x >> y;
        S.insert(tran(x,y));
    }
    cin >> x >> y;
    pocz = tran(x,y);
    x = pocz.X; y = pocz.Y;
    cin >> dirp;
    if(dirp == "NE") k = 3;
    if(dirp == "SE") k = 0;
    if(dirp == "SW") k = 1;
    if(dirp == "NW") k = 2;
	//G
    FORE(i,S) {
//        cout << i->X-MAXN/2 << " " << i->Y-MAXN/2 << endl;
        v[0][i->X].PB(i->Y);
        v[1][i->Y].PB(i->X);
    }
    REP(i,MAXN) REP(j,2) {
        sort(ALL(v[j][i]));
    }
    //sol
    move();
    while(!vis[PP(P(x,y),k)]) {
        vis[PP(P(x,y),k)] = 1;
        move();
    }
    while(vis[PP(P(x,y),k)] != 2) {
        vis[PP(P(x,y),k)] = 2;
        int prevx = x, prevy = y;
        move();
        if(x == prevx) odc[0][x].PB(P(min(y,prevy), max(y,prevy)));
        else odc[1][y].PB(P(min(x,prevx), max(x,prevx)));
    }
    REP(i,2) REP(j,MAXN) {
        sort(ALL(odc[i][j]));
        odc[i][j].erase(unique(ALL(odc[i][j])), odc[i][j].end());
        FORE(q,odc[i][j]) res += (q->Y-q->X)/2;
    }
	//out
    cout << res << endl;
	return 0;
}