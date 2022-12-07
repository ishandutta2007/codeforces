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
	int t,n,x,y,z;
	bool v;
	cin>>t;
	rep(tt,t){
		cin>>n;
		cin>>x;
		if(n>1)cin>>y;
		v=false;
		rep(i,n-2){
			cin>>z;
			if((z!=x)&&(z!=y))v=true;
		}
		if(n%2==1)cout<<n<<"\n";
		else if(v)cout<<n<<"\n";
		else cout<<((n/2)+1)<<"\n";
	}
    
	return 0;
}