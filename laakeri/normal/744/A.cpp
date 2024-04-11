#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[101010];
int u[101010];
int dfs(int x){
	if (u[x]) return 0;
	u[x]=1;
	int r=1;
	for (int nx:g[x]){
		r+=dfs(nx);
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> c(k);
	for (int i=0;i<k;i++) cin>>c[i];
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll m2=0;
	vector<int> ccs;
	for (int i=0;i<k;i++){
		int s=dfs(c[i]);
		ccs.push_back(s);
	}
	sort(ccs.begin(), ccs.end());
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			int s=dfs(i);
			ccs.back()+=s;
		}
	}
	for (ll cc:ccs){
		m2+=(cc*(cc-1ll))/2ll;
	}
	cout<<m2-(ll)m<<endl;
}