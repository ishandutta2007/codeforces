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
#define MAXN 200007

struct DP{
    typedef int TYP;
    TYP tab[MAXN];

    void add(int x, TYP w){
        while(x < MAXN) {tab[x] += w; x += x&-x;}
    }

    TYP get(int x){
        TYP res = 0;
        while(x) {res += tab[x]; x -= x&-x;}
        return res;
    }

    TYP get(int a,int b){return get(b)-get(a-1);}
};

DP dp;
int n,p[MAXN],m,l[MAXN],r[MAXN],where[MAXN],ans[MAXN];
VI G[MAXN];
vector<P> Q[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m;
    FOR(i,1,n) cin >> p[i];
    FOR(i,1,m) cin >> l[i] >> r[i];
	//sol
    FOR(i,1,n) where[p[i]] = i;
    FOR(i,1,n) for(int j=i; j<=n; j+=i) {
        int a = where[i];
        int b = where[j];
        if(a < b) swap(a,b);
        G[a].PB(b);
    }
    FOR(i,1,m) Q[r[i]].PB(P(i,l[i]));
    FOR(i,1,n) {
        FORE(j,G[i]) dp.add(*j, 1);
        FORE(j,Q[i]) ans[j->X] = dp.get(j->Y, i);
    }
	//out
    FOR(i,1,m) cout << ans[i] << endl;
	return 0;
}