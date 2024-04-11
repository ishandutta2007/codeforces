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
  int t;
  string str,ans;
	int n,k,m;
  int x;
  int a[26];
  cin>>t;
  rep(tt,t){
    cin>>n>>k;
    cin>>str;
    m=n/k;
    ans="";
    rep(i,26)a[i]=0;
    rep(i,n)a[(str[i]-'a')]++;
    rep(i,k){
      x=m;
      rep(j,26){
        if((x==0)||(a[j]==0)){
          ans+=((char)('a'+j));
          break;
        }
        else {
          a[j]--;
          x--;
        }
      }
    }
    cout<<ans<<endl;
  }

    
	return 0;
}