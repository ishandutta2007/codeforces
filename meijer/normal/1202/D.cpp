#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,b) REP(a,0,b)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e18
#define pb push_back
#define fi first
#define se second

const int MX=50000;
int t, n;
int fact[MX], cnt[MX];

int main() {
  fact[1] = 1;
  REP(i,2,MX) fact[i] = fact[i-1]+i;
  cin>>t;
  while(t--) {
    cin>>n;
    RE(i,MX) cnt[i] = 0;
    REV(i,1,MX) {
      while(n >= fact[i])
        n -= fact[i], cnt[i]++;
    }
    string s;
    s.reserve(1e5);
    s.pb('1');
    REP(i,0,MX) {
      s.pb('3');
      while(cnt[i]--)
        s.pb('7');
    }
    cout<<s<<endl;
  }
}