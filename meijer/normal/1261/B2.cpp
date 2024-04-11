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
 
const ll MX=5e5, MOD=1e9+7;
int n, a[MX], m, k, pos, SA[MX];
vii queries[MX];
int ans[MX];
int BIT[MX];

void addValue(int i, int v) {
  for(i++; i<=n; i+=i&-i)
    BIT[i] += v;
}
int getValue(int i) {
  int ans=0;
  for(i++; i>0; i-=i&-i)
    ans += BIT[i];
  return ans;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  RE(i,n) cin>>a[i];
  RE(i,n) SA[i] = i, BIT[i]=0;
  sort(SA, SA+n, [](int i, int j) {
    if(a[i] == a[j])
      return i<j;
    return a[i]>a[j];
  });
  cin>>m;
  RE(i,m) {
    cin>>k>>pos;
    queries[k-1].pb({pos,i});
  }
  RE(i,n) {
    addValue(SA[i], 1);
    for(ii p:queries[i]) {
      int x=p.fi, q=p.se;
      int lb=0, ub=n-1;
      while(lb != ub) {
        int mid=(lb+ub)/2;
        if(getValue(mid) >= x) ub=mid;
        else lb=mid+1;
      }
      ans[q] = lb;
    }
  }
  RE(i,m) cout<<a[ans[i]]<<endl;
}