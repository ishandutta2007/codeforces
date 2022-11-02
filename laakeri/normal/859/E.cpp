#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

int od[202020];
int id[202020];

vector<int> rg[202020];
vector<int> bg[202020];

int u[202020];

ll dfs(int x){
	u[x]=1;
	ll r=1;
	for (int nx:rg[x]){
		r+=dfs(nx);
	}
	return r;
}

int dfs2(int x){
	if (u[x]) return 0;
	u[x]=1;
	int r=1;
	for (int nx:bg[x]){
		r+=dfs2(nx);
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		bg[a].push_back(b);
		bg[b].push_back(a);
		
		rg[b].push_back(a);
		od[a]++;
		id[b]++;
	}
	ll v=1;
	for (int i=1;i<=2*n;i++){
		if (od[i]==0){
			v*=dfs(i);
			v%=mod;
		}
	}
	queue<int> q;
	for (int i=1;i<=2*n;i++){
		if (id[i]==0&&u[i]==0){
			q.push(i);
			u[i]=1;
		}
	}
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int nx:bg[x]){
			id[nx]--;
			if (id[nx]==0&&u[nx]==0) {
				u[nx]=1;
				q.push(nx);
			}
		}
	}
	for (int i=1;i<=2*n;i++){
		if (bg[i].size()>0&&u[i]==0){
			if (dfs2(i)>1){
				v*=2ll;
				v%=mod;
			}
		}
	}
	cout<<v<<endl;
}