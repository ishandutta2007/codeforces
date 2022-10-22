#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
 
const ll MX=6e5, MOD=1e9+7;
int t, n, k;
string s, T;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--) {
    cin>>n>>k;
    cin>>s;
    T.resize(s.size());
    k--;
    RE(i,k) {
      T[i*2  ] = '(';
      T[i*2+1] = ')';
    }
    RE(i,(n-k*2)/2) T[k*2+i] = '(';
    RE(i,(n-k*2)/2) T[n-i-1] = ')';
    int l = n-1;
    vii ans;
    REV(i,0,n) {
      if(s[i] == T[i]) {
        l = min(l,i-1);
        continue;
      }
      while(s[l] != T[i])
        l--;
      swap(s[l], s[i]);
      ans.pb({l+1,i+1});
    }
    cout<<ans.size()<<endl;
    RE(i,ans.size()) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
  }
}