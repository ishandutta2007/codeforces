#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define RE(a,b) REP(a,0,b)
#define RE1(a,b) REP(a,1,b+1)
#define FOR(a,b) for(auto& a : b)
#define pb push_back
#define all(a) a.begin(),a.end()
#define fi first
#define se second

const int INF	= 1e9;
const int MX	= 110;
const int N	= 1<<20;
const int MOD	= 1e9+7;

ll n, k, a[MX];

struct Mat {
  ll b[MX][MX];
  Mat() {
    RE(i,MX) RE(j,MX) b[i][j] = 0;
  }
  Mat operator*(Mat rhs) {
    Mat res;
    RE(i,MX) RE(j,MX) RE(k,MX) res.b[i][k] += (b[i][j]*rhs.b[j][k])%MOD;
    RE(i,MX) RE(j,MX) res.b[i][j] %= MOD;
    return res;
  }
};

Mat ways[63];
Mat comb;

int main() {
  cin>>n>>k; k--;
  RE(i,n) cin>>a[i];
  
  RE(i,n) ways[0].b[i][i] = 1;

  RE(i,n) RE(j,n) comb.b[i][j] = ((__builtin_popcountll(a[i]^a[j])%3)==0 ? 1 : 0);

  REP(i,1,63) ways[i] = ways[i-1]*comb*ways[i-1];

  Mat res = ways[0];
  RE(i,63) {
    if(k&(1ll<<ll(i))) {
      res = res*comb*ways[i];
    }
  }

  ll ans = 0;
  RE(i,MX) RE(j,MX) ans += res.b[i][j];
  ans %= MOD;
  cout << ans << endl;
}