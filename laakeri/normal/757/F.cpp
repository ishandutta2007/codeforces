#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<int, ll> > g[202020];
int u[202020];
int bc[202020];
int b[202020];
vector<int> fr[202020];
ll d[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,s;
	cin>>n>>m>>s;
	for (int i=0;i<m;i++){
		int uu,v,w;
		cin>>uu>>v>>w;
		g[uu].push_back({v, w});
		g[v].push_back({uu, w});
	}
	priority_queue<pair<ll, int> > dij;
	d[s]=1;
	dij.push({-1, s});
	while (!dij.empty()){
		auto xx=dij.top();
		dij.pop();
		int x=xx.S;
		if (u[x]) continue;
		u[x]=1;
		int f=0;
		for (int ex:fr[x]){
			if (f==0){
				f=bc[ex];
			}
			else if(f>0){
				if (f!=bc[ex]){
					f=-1;
				}
			}
		}
		if (f<=0){
			bc[x]=x;
		}
		else{
			bc[x]=f;
		}
		if (bc[x]==s) bc[x]=x;
		if (bc[x]!=s) b[bc[x]]++;
		for (auto nx:g[x]){
			if (d[nx.F]==0||d[x]+nx.S<d[nx.F]){
				d[nx.F]=d[x]+nx.S;
				fr[nx.F].clear();
				fr[nx.F].push_back(x);
				dij.push({-d[nx.F], nx.F});
			}
			else if(d[x]+nx.S==d[nx.F]){
				fr[nx.F].push_back(x);
			}
		}
	}
	int v=0;
	for (int i=1;i<=n;i++){
		v=max(v, b[i]);
	}
	cout<<v<<endl;
}