#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,b) REP(a,0,b)
#define INF 1e18
#define pb push_back
#define fi first
#define se second

const int MX=5e5;
int T, n, m, a, b;
bitset<MX> usedNode;
vi matching;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>T;
  while(T--) {
    cin>>n>>m;

    matching.clear();
    RE(i,n*3) usedNode[i] = 0;
    
    RE(i,m) {
      cin>>a>>b, a--, b--;
      if(!usedNode[a] && !usedNode[b]) {
        usedNode[a] = 1;
        usedNode[b] = 1;
        matching.pb(i+1);
      }
    }
    if(matching.size() >= n) {
      cout<<"Matching"<<endl;
      RE(i,n) cout<<(i==0?"":" ")<<matching[i]; cout<<endl;
    } else {
      cout<<"IndSet"<<endl;
      int j=0;
      RE(i,n*3) {
        if(usedNode[i]) continue;
        cout<<(j++==0?"":" ")<<i+1;
        if(j == n) break;
      }
      cout<<endl;
    }
  }
}