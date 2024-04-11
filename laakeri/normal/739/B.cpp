#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll a[202020];
ll w[202020][20];
int p[202020][20];

int has[202020];
int ans[202020];

vector<int> g[202020];

int dfs(int x, int pp){
	int c=0;
	for (int nx:g[x]){
		if (nx!=pp) c+=dfs(nx, x);
	}
	ans[x]=c;
	c+=has[x];
	return c;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=2;i<=n;i++){
		cin>>p[i][0]>>w[i][0];
		g[i].push_back(p[i][0]);
		g[p[i][0]].push_back(i);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<20;j++){
			p[i][j]=p[p[i][j-1]][j-1];
			w[i][j]=w[i][j-1]+w[p[i][j-1]][j-1];
		}
	}
	for (int i=1;i<=n;i++){
		ll x=a[i];
		int t=i;
		for (int j=19;j>=0;j--){
			while (p[t][j]!=0&&w[t][j]<=x){
				x-=w[t][j];
				t=p[t][j];
			}
		}
		if (t==0) t=1;
		has[i]++;
		has[t]--;
	}
	dfs(1, 0);
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
}