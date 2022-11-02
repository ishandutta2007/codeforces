#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1e6;

vector<int> g[3030];

int d[3030][3030];
int n;

vector<pair<int, int> > dto[3030];
vector<pair<int, int> > dfrom[3030];

void gobfs(int x){
	for (int i=1;i<=n;i++){
		d[x][i]=inf;
	}
	queue<int> bfs;
	bfs.push(x);
	d[x][x]=0;
	while (!bfs.empty()){
		int t=bfs.front();
		bfs.pop();
		for (int nx:g[t]){
			if (d[x][nx]==inf){
				d[x][nx]=d[x][t]+1;
				bfs.push(nx);
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (i!=x&&d[x][i]<inf){
			dfrom[x].push_back({d[x][i], i});
			dto[i].push_back({d[x][i], x});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	for (int i=1;i<=n;i++){
		gobfs(i);
	}
	for (int i=1;i<=n;i++){
		sort(dfrom[i].begin(), dfrom[i].end());
		sort(dto[i].begin(), dto[i].end());
	}
	int v=0;
	int v1=0;
	int v2=0;
	int v3=0;
	int v4=0;
	for (int i=1;i<=n;i++){
		for (int ii=1;ii<=n;ii++){
			if (i!=ii&&d[i][ii]<inf){
				for (int j=(int)dto[i].size()-1;j>=max((int)dto[i].size()-10, 0);j--){
					if (dto[i][j].S!=i&&dto[i][j].S!=ii){
						for (int jj=(int)dfrom[ii].size()-1;jj>=0;jj--){
							if (dfrom[ii][jj].S!=i&&dfrom[ii][jj].S!=ii&&dfrom[ii][jj].S!=dto[i][j].S){
								if (d[i][ii]+dto[i][j].F+dfrom[ii][jj].F>v){
									v=d[i][ii]+dto[i][j].F+dfrom[ii][jj].F;
									v1=dto[i][j].S;
									v2=i;
									v3=ii;
									v4=dfrom[ii][jj].S;
								}
								break;
							}
						}
					}
				}
			}
		}
	}
	cout<<v1<<" "<<v2<<" "<<v3<<" "<<v4<<endl;
}