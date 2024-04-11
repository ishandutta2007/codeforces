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
const LL MOD=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007

struct DP{
    typedef LL TYP;
    TYP tab[MAXN];

    void add(int x, TYP w){
        while(x < MAXN) {tab[x] += w; tab[x] %= MOD; x += x&(-x); }
    }

    TYP get(int x){
        TYP res = 0;
        while(x) {res += tab[x]; res %= MOD; x -= x&(-x);}
        return res;
    }

    TYP get(int a,int b){return get(b)-get(a-1);}
};
DP dp;

LL n,a[MAXN],last[MAXN];
LL res;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    FOR(i,1,n) cin >> a[i];
	//sol
    FOR(i,1,n) {
        LL val = dp.get(a[i]) + 1;
        val *= a[i];
        val %= MOD;
        LL vis = last[a[i]];
        last[a[i]] = val;
//        cout << a[i] << "->" << val << " " << vis << endl;
        val -= vis;
        val %= MOD;
        dp.add(a[i], val);
        res += val;
        res %= MOD;
    }
	//out
    res %= MOD;
    if(res < 0) res += MOD;
    cout << res << endl;
	return 0;
}