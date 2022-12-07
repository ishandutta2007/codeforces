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
	int t,n,sz;
	string s[101];
	vector<int>a;
	cin>>t;
	rep(tt,t){
		cin>>n;
		rep(i,n)cin>>s[i];
		rep(i,n){
			a.clear();
			rep(j,n)if((s[j][i]=='1')||(j==i))a.pb(j+1);
			sz=a.size();
			cout<<sz;
			rep(i,sz)cout<<" "<<a[i];
			cout<<"\n";
		}
	}
    
	return 0;
}