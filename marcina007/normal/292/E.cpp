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
#define BASE (1<<18)

struct DP {
    int dp[2*BASE];
    bool bit[2*BASE];
    DP(){CLR(dp);}

    void check(int x){
            if(bit[x]) {
                bit[x] = false;
                bit[x+x] = bit[x+x+1] = true;
                dp[x+x] = dp[x+x+1] = dp[x];
            }
    }

    void set(int l, int r, int v, int x = 1, int ll = 1, int rr = BASE) {
        if(r < ll || rr < l) return;
        if(l <= ll && rr <= r) { //przedzial basowy
            dp[x] = v;
            bit[x] = true;
        } else { //nadprzedzial
            check(x);
            set(l, r, v, x+x, ll, (ll+rr)/2);
            set(l, r, v, x+x+1, (ll+rr+1)/2, rr);
            //update
        }
    }
    int get(int l, int r, int x = 1, int ll = 1, int rr = BASE) {
        if(r < ll || rr < l) return 0;
        if(l <= ll && rr <= r) { //przedzial basowy
            return dp[x];
        } else { //nadprzedzial
            check(x);
            return get(l, r, x+x, ll, (ll+rr)/2) + 
            get(l, r, x+x+1, (ll+rr+1)/2, rr);
        }
    }

};

DP dp;
int a[MAXN],n,m;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m;
    FOR(i,1,2*n) cin >> a[i];
	//sol
    dp.set(1,n,n);
    while(m--) {
        int t, x, y, k;
        cin >> t;
        if(t == 1) {
            cin >> x >> y >> k;
            dp.set(y, y+k-1, x-y);
        } else {
            cin >> x;
            cout << a[x + dp.get(x,x)] << endl;
        }
    }
	//out
	return 0;
}