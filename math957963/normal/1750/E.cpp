#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
#define M (ll)1e+12
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;


int main() {
  int t,n,x;
  string s;
  ll mx,mn,y,z,mid;
  vector<pii>b;
  set<int>st;
  set<int>::iterator itr;
  cin>>t;
  rep(tt,t){
    cin>>n;
    cin>>s;
    b.clear();
    x=0;
    b.pb({x,0});
    rep(i,n){
      if(s[i]=='(')x++;
      else x--;
      b.pb({x,i+1});
    }
    n++;
    sort(all(b));
    mx=0;
    rep(i,n){
      z=i+1;
      z=(z*b[i].first);
      mx=(mx+z);
    }
    st.clear();
    st.insert(-1);
    st.insert(n);
    mn=0;
    rep(i,n){
      itr=st.upper_bound(b[i].second);
      z=(*itr);
      itr--;
      y=(*itr);
      mid=b[i].second;
      mid=((mid-y)*(z-mid));
      mid=(mid*b[i].first);
      mn=(mn+mid);
      st.insert(b[i].second);
    }
    cout<<(mx-mn)<<endl;
  }
    
	return 0;
}