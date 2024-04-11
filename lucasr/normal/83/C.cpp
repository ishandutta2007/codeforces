#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define bits(x) __builtin_popcount(x)

#define INF 1000000000

string mat[50];
bool allow[26];

bool isAllow(char c) {
	return c=='T' || c=='S' || allow[c-'a'];
}

int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};
int dist[50][50];
pair<int, int>  pa[50][50];

int n,m;

bool in(int a, int b) {
	return 0<=a && a<n && 0<=b && b<m;
}

void bfs(int x, int y) {
	pair<int, int> orig=make_pair(x,y);
	queue<pair<int, int> > cola;
	memset(dist, -1, sizeof(dist));
	int vis[n][m];
	memset(vis,0,sizeof(vis));
	cola.push(orig);
	vis[x][y]=true;
	dist[x][y]=0;
	while (!cola.empty()) {
		pair<int, int> cu=cola.front(); cola.pop();
		int xx=cu.first, yy=cu.second;
		for (int k=0;k<4;k++) {
			int nx=xx+di[k], ny=yy+dj[k];
			if (in(nx, ny) && isAllow(mat[nx][ny])) {
				//cout<<"visiting: "<<nx<<" "<<ny<<endl;
				if (!vis[nx][ny]) {
					//cout<<"First: "<<nx<<" "<<ny<<endl;
					dist[nx][ny]=dist[xx][yy]+1;
					pa[nx][ny]=cu;
					vis[nx][ny]=true;
					cola.push(make_pair(nx,ny));
				} else if (dist[nx][ny]==dist[xx][yy]+1) {
					pair<int, int>  p1=cu,p2=pa[nx][ny];
					while (p1!=orig && mat[p1.first][p1.second]==mat[p2.first][p2.second]) {
						p1=pa[p1.first][p1.second];
						p2=pa[p2.first][p2.second];
					}
					if (p1!=orig && mat[p1.first][p1.second] < mat[p2.first][p2.second]) {
						pa[nx][ny]=cu;
					}
				}
			}
		}
	}
}

int main(){
	int kk;
	cin>>n>>m>>kk;
	int xS, yS, xT, yT;
	
	for (int i=0;i<n;i++) {
		cin>>mat[i];
	}
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
		if (mat[i][j]=='S') {
			xS=i; yS=j;
		}
		if (mat[i][j]=='T') {
			xT=i; yT=j;
		}
	}
	
	pair<int, int> final=make_pair(xT,yT);
	string best;
	int largo=INF;
	memset(allow,0,sizeof(allow));
	bool first = true;
	for (int i=0;i<26;i++) for (int j=i;j<26;j++) for (int k=j;k<26;k++) for (int h=k;h<26;h++) {
		if (kk<4) h=i;
		if (kk<3) k=i;
		if (kk<2) j=i;
		allow[i]=allow[j]=allow[k]=allow[h]=true;
		bfs(xT, yT);
		if (dist[xS][yS]!=-1) {
			//if (first) for (int ii=0;ii<n;ii++) { for (int jj=0;jj<m;jj++) cout<<dist[ii][jj]<<" "; cout<<endl; first=false;}
			int cu=dist[xS][yS];
			if (cu<=largo) {
				string curS="";
				pair<int,int> po=pa[xS][yS];
				while (po!=final) {
					curS+=mat[po.first][po.second];
					po=pa[po.first][po.second];
				}
				if (cu < largo) {
					largo=cu;
					best=curS;
				} else if (cu==largo && best > curS) {
					best = curS;
				}
			}
		}
		allow[i]=allow[j]=allow[k]=allow[h]=false;
		if (kk<4) h=26;
		if (kk<3) k=26;
		if (kk<2) j=26;
	}
	
	if (largo>=INF) cout<<"-1"<<endl;
	else {
		cout<<best<<endl;
	}
	return 0;
}