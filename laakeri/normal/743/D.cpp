#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[202020];

const ll inf=1e18;
const ll lol=1e10;

ll a[202020];

pair<ll, pair<ll, ll> > dfs(int x, int p){
	ll tsu=a[x];
	ll m1=-inf;
	ll m2=-inf;
	for (int nx:g[x]){
		if (nx!=p){
			auto asd=dfs(nx, x);
			tsu+=asd.F;
			m2=max(m2, asd.S.S);
			m2=max(m2, m1+asd.S.F);
			m1=max(m1, asd.S.F);
		}
	}
	m1=max(m1, tsu);
	return {tsu, {m1, m2}};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto ans=dfs(1, 0);
	if (ans.S.S<-lol){
		cout<<"Impossible"<<endl;
	}
	else{
		cout<<ans.S.S<<endl;
	}
}