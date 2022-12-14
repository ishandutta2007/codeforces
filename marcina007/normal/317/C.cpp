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
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 307
#define MOVES 1000007

int n,v,e;
int a[MAXN],b[MAXN];
VI GG[MAXN],G[MAXN];
bool del[MAXN], vis[MAXN];
int xx[MOVES], yy[MOVES], dd[MOVES], moves;

LL go(int x) {
    LL res = a[x] - b[x];
    vis[x] = true;
    FORE(i,GG[x]) if(!vis[*i]) {
        G[x].PB(*i);
        G[*i].PB(x);
        res += go(*i);
    }
    return res;
}

void push(int x,int o,int lim,bool down) {
    FORE(i,G[x]) if(*i != o && !del[*i]) {
        push(*i, x, INF, down);
        int can = lim;
        int l = x, r = *i;
        if(!down) swap(l,r);
        mini(can, a[l]);
        mini(can, v-a[r]);
        lim -= can;
        if(can > 0) {
            a[l] -= can;
            a[r] += can;
            xx[moves] = l;
            yy[moves] = r;
            dd[moves] = can;
            moves++;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> v >> e;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
    while(e--) {
        int x,y;
        cin >> x >> y;
        GG[x].PB(y);
        GG[y].PB(x);
    }
    //sol
    FOR(i,1,n) if(!vis[i]) if(go(i) != 0) {cout << "NO" << endl; return 0;}
    bool ok;
    do {
        ok = false;
        FOR(i,1,n) if(!del[i]) {
            int deg = 0;
            FORE(j,G[i]) deg += !del[*j];
            if(deg != 1) continue;
            if(a[i] != b[i])
                push(i, i, abs(a[i] - b[i]), a[i] > b[i]);
            assert(a[i] == b[i]);
            del[i] = true;
            ok = true;
            break;
        }
    } while(ok);
    FOR(i,1,n) assert(a[i] == b[i]);
	//out
    cout << moves << endl;
    REP(i,moves) cout << xx[i] << " " << yy[i] << " " << dd[i] << endl;
	return 0;
}