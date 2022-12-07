#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
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
	int t,n;
  string s;
  ll cnt0,cnt1,c,m;
	cin>>t;
  rep(tt,t){
    cin>>n;
    cin>>s;
    m=0;
    c=0;
    cnt0=0;
    cnt1=0;
    rep(i,n){
      if(s[i]=='0')cnt0++;
      if(s[i]=='1')cnt1++;
      if(i==0)c++;
      else{
        if(s[i]==s[i-1])c++;
        else{
          m=max(m,c);
          c=1;
        }
      }
    }
    m=max(m,c);
    m=max(m*m,cnt0*cnt1);
    cout<< m <<"\n";
  }
    
	return 0;
}