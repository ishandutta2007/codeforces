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
template<class C> void maxii(C&a4, C b4){a4=maxi(a4, b4); }
#define BASE (1<<17)

struct DP {
    LL sum[2*BASE+3], maxi[2*BASE+3];

    void set(int l, int r, int v, int x = 1, int ll = 1, int rr = BASE) {
        if(r < ll || rr < l) return;
        if(l <= ll && rr <= r) { //przedzial basowy
          sum[x] = maxi[x] = v;
        } else { //nadprzedzial
            set(l, r, v, x+x, ll, (ll+rr)/2);
            set(l, r, v, x+x+1, (ll+rr+1)/2, rr);
            //update
            sum[x] = sum[x+x] + sum[x+x+1];
            maxi[x] = max(maxi[x+x], maxi[x+x+1]);
        }
    }

    void mod(int l, int r, int v, int x = 1, int ll = 1, int rr = BASE) {
        if(r < ll || rr < l) return;
        if(maxi[x] < v) return;
        if(ll == rr) { //przedzial jednostkowy
          //cout << " mod " << ll << endl;
          sum[x] = maxi[x] = (sum[x] % v);
        } else { //nadprzedzial
            mod(l, r, v, x+x, ll, (ll+rr)/2);
            mod(l, r, v, x+x+1, (ll+rr+1)/2, rr);
            //update
            sum[x] = sum[x+x] + sum[x+x+1];
            maxi[x] = max(maxi[x+x], maxi[x+x+1]);
        }
    }

    LL get(int l, int r, int x = 1, int ll = 1, int rr = BASE) {
        if(r < ll || rr < l) return 0;
        if(l <= ll && rr <= r) { //przedzial basowy
            return sum[x];
        } else { //nadprzedzial
            return get(l, r, x+x, ll, (ll+rr)/2) +
            get(l, r, x+x+1, (ll+rr+1)/2, rr);
        }
    }

};

DP dp;

int n,m,a[BASE+3];

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m;
    FOR(i,1,n) cin >> a[i];
	//sol
    FOR(i,1,n) dp.set(i,i,a[i]);
    while(m--) {
//    FOR(i,1,n) cout << dp.get(i,i) << " "; cout << endl;
      int t,a,b,c;
      cin >> t >> a >> b;
      if(t == 1) {
        cout << dp.get(a,b) << endl;
      } else if(t == 2) {
        cin >> c;
        dp.mod(a,b,c);
      } else if(t == 3) {
        dp.set(a,a,b);
      }
    }
	//out
	return 0;
}