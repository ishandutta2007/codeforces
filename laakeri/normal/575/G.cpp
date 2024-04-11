#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<pair<int, int> > g[101010];

vector<int> g2[101010];
int d[101010];
int ek[101010];
int ekd[101010];

int used[101010];

int from[101010];
int from2[101010];

int hk[101010][10];
int mik[101010];

vector<int> h[101010];

void dfs1(int x){
	if (ek[x]) return;
	ek[x]=1;
	for (int nx:g2[x]){
		dfs1(nx);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<101010;i++){
		ekd[i]=9999999;
	}
	for (int i=0;i<m;i++){
		int a,b,x;
		cin>>a>>b>>x;
		g[a].push_back({b, x});
		g[b].push_back({a, x});
		if (x==0){
			g2[a].push_back(b);
			g2[b].push_back(a);
		}
	}
	dfs1(n-1);
	queue<pair<int, int> > bfs0;
	bfs0.push({n-1, 1});
	while (!bfs0.empty()){
		auto x=bfs0.front();
		bfs0.pop();
		if (!ek[x.F]) continue;
		if (ekd[x.F]<9999999) continue;
		ekd[x.F]=x.S;
		for (int nx:g2[x.F]){
			bfs0.push({nx, x.S+1});
		}
	}
	
	queue<pair<int, int> > bfs;
	bfs.push({0, 1});
	int df=-1;
	while (!bfs.empty()){
		auto x=bfs.front();
		bfs.pop();
		if (d[x.F]) continue;
		d[x.F]=x.S;
		if (ek[x.F]){
			if (df==-1||df==x.S){
				df=x.S;
				if (!used[x.F]) {
					mik[x.F]=1;
					hk[df][0]=1;
					h[x.S].push_back(x.F);
					used[x.F]=1;
					from[x.F]=-1;
				}
			}
		}
		for (auto nx:g[x.F]){
			bfs.push({nx.F, x.S+1});
		}
	}
	for (int i=df;i>1;i--){
		for (int j=0;j<10;j++){
			if (hk[i][j]){
				for (int x:h[i]){
					//cout<<x<<endl;
					if (mik[x]==j+1){
						for (auto nx:g[x]){
							if (d[nx.F]==i-1){
								hk[i-1][nx.S]=1;
								if (mik[nx.F]==0){
									mik[nx.F]=nx.S+1;
									from[nx.F]=x;
									ekd[nx.F]=ekd[x];
								}
								else{
									if (nx.S+1<mik[nx.F]){
										from[nx.F]=x;
										mik[nx.F]=nx.S+1;
										ekd[nx.F]=ekd[x];
									}
									else if(nx.S+1==mik[nx.F]){
										if (ekd[x]<ekd[nx.F]){
											from[nx.F]=x;
											ekd[nx.F]=ekd[x];
										}
									}
								}
								if (!used[nx.F]){
									h[i-1].push_back(nx.F);
									used[nx.F]=1;
								}
							}
						}
					}
				}
				break;
			}
		}
	}
	for (int i=0;i<101010;i++){
		from2[i]=-1;
	}
	for (int j=0;j<10;j++){
		if ((int)h[1].size()>0){
			for (int x:h[1]){
				if (x==0&&mik[x]==j+1){
					vector<int> vv;
					vector<int> v2;
					int xx=x;
					while (from[xx]>-1){
						int mi=10;
						for (auto nx:g[xx]){
							if (nx.F==from[xx]&&ekd[nx.F]==ekd[xx]){
								mi=min(mi, nx.S);
							}
						}
						vv.push_back(mi);
						v2.push_back(xx);
						xx=from[xx];
						assert((int)v2.size()<200000);
					}
					v2.push_back(xx);
					for (int i=(int)vv.size()-1;i>=0;i--){
						cout<<vv[i];
					}
					if ((int)vv.size()==0){
						cout<<0;
					}
					cout<<endl;
					if (v2.back()!=n-1){
						int fo=0;
						queue<int> bfs2;
						bfs2.push(v2.back());
						while (!bfs2.empty()){
							int xxx=bfs2.front();
							bfs2.pop();
							if (xxx==n-1){
								fo=1;
								break;
							}
							for (int nx:g2[xxx]){
								if (from2[nx]==-1){
									bfs2.push(nx);
									from2[nx]=xxx;
								}
							}
						}
						assert(fo==1);
						vector<int> lol;
						int t=n-1;
						while (t!=v2.back()){
							lol.push_back(t);
							//assert((int)lol.size()<200000);
							t=from2[t];
						}
						for (int i=(int)lol.size()-1;i>=0;i--){
							v2.push_back(lol[i]);
						}
					}
					cout<<v2.size()<<endl;
					for (int v:v2){
						cout<<v<<" ";
					}
					cout<<endl;
					return 0;
				}
			}
		}
	}
}