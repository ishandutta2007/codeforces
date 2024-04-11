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

vector<int>e[N];
ll sc[N];

pll dfs(int k,int num){
	int sz=e[k].size();
	int r=num%sz;
	ll ret1=num*sc[k];
	if(sz==0)return {ret1,sc[k]};
	vector<ll>a;
	pll b;
	rep(i,sz){
		b=dfs(e[k][i],num/sz);
		ret1+=b.first;
		a.pb(b.second);
	}
	sort(all(a),greater<ll>());
	rep(i,r)ret1+=a[i];
	return {ret1,sc[k]+a[r]};
}


int main() {
	int t,n,x;
	ll m;
	cin >> t;
	rep(tt,t){
		cin>>n>>m;
		rep(i,n-1){
			cin>>x;
			e[x-1].pb(i+1);
		}
		rep(i,n){
			cin>>sc[i];
		}
		cout<<dfs(0,m).first<<endl;
		rep(i,n)e[i].clear();
	}
    
	return 0;
}