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
#define DEBUG 0
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef pair<P, int>PP;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 20007

int n,m,k,uf[MAXN],cc,ans[MAXN];
vector<P> G;
VI pocz, kon;

int find(int x){
    while(uf[x] != x) {
        uf[x] = uf[uf[x]];
        x = uf[x];
    }
    return x;
}

bool join(int a,int b){
    debug("join" << a << " " << b)
    a = find(a);
    b = find(b);
    if(a != b) {
        cc--;
        uf[a] = b;
        return true;
    }
    return false;
}

void clear(){
    FOR(i,1,n) uf[i] = i;
    cc = n;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m;
    G.PB(P(0,0));
    FOR(i,1,m){
        int a,b;
        cin >> a >> b;
        G.PB(P(a,b));
    }
	//sol
    clear();
    FOR(i,1,m)
        if(join(G[i].X, G[i].Y))
            pocz.PB(i);
    clear();
    FORD(i,m,1)
        if(join(G[i].X, G[i].Y))
            kon.PB(i);
    //out
    cin >> k;
    while(k--){
        int l,r;
        cin >> l >> r;
        clear();
        FORE(i,pocz) {
            if(*i >= l) break;
            join(G[*i].X, G[*i].Y);
        }
        FORE(i,kon) {
            if(*i <= r) break;
            join(G[*i].X, G[*i].Y);
        }
        cout << cc << endl;
    }
	return 0;
}