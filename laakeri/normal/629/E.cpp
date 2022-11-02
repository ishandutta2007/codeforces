#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll aps[101010];
ll dp[101010];
int p[101010][20];
int d[101010];
vector<int> g[101010];

int lca(int a, int b){
	if (d[a]<d[b]) swap(a, b);
	for (int i=18;i>=0;i--){
		if (d[a]-d[b]>=(1<<i)){
			a=p[a][i];
		}
	}
	if (a==b) return a;
	for (int i=18;i>=0;i--){
		if (p[a][i]!=p[b][i]){
			a=p[a][i];
			b=p[b][i];
		}
	}
	return p[a][0];
}

void dfs0(int x, int pa){
	p[x][0]=pa;
	for (int i=1;i<20;i++){
		p[x][i]=p[p[x][i-1]][i-1];
	}
	aps[x]=1;
	for (int nx:g[x]){
		if (nx!=pa){
			d[nx]=d[x]+1;
			dfs0(nx, x);
			aps[x]+=aps[nx];
			dp[x]+=dp[nx]+aps[nx];
		}
	}
}

map<int, vector<pair<int, int> > > q2[101010];
ll vv[101010];
ll vc[101010];

void dfs1(int x, int pa, ll ps, ll pdp){
	for (int nx:g[x]){
		if (nx!=pa){
			aps[x]-=aps[nx];
			dp[x]-=dp[nx]+aps[nx];
			
			aps[x]+=ps;
			dp[x]+=pdp+ps;
			
			for (auto qq:q2[x][nx]){
				//cout<<x<<" "<<qq.F<<" "<<qq.S<<" "<<aps[x]<<" "<<aps[qq.F]<<endl;
				ll d0=d[qq.F]-d[x];
				vc[qq.S]=aps[x]*aps[qq.F];
				vv[qq.S]=vc[qq.S]*d0+dp[x]*aps[qq.F]+dp[qq.F]*aps[x]+vc[qq.S];
			}
			
			dfs1(nx, x, aps[x], dp[x]);
			
			aps[x]-=ps;
			dp[x]-=pdp+ps;
			
			aps[x]+=aps[nx];
			dp[x]+=dp[nx]+aps[nx];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs0(1, 0);
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		int l=lca(a, b);
		if (l!=a&&l!=b){
			ll d0=d[a]+d[b]-2*d[l];
			vc[i]=aps[a]*aps[b];
			vv[i]=vc[i]*d0+dp[a]*aps[b]+dp[b]*aps[a]+vc[i];
		}
		else{
			if (a==l) swap(a, b);
			int aa=a;
			int de=d[a]-d[l]-1;
			for (int j=18;j>=0;j--){
				if ((1<<j)<=de){
					aa=p[aa][j];
					de-=(1<<j);
				}
			}
			q2[l][aa].push_back({a, i});
		}
	}
	dfs1(1, 0, 0, 0);
	cout<<setprecision(15);
	for (int i=0;i<m;i++){
		cout<<(ld)vv[i]/(ld)vc[i]<<'\n';
	}
}