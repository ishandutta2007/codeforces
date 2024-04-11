#include<bits/stdc++.h>
#define to first
#define val second
using namespace std;
int const N=3010,INF=0x3f3f3f3f;
int n,f[N][8][2],g[8][2];
vector<pair<int,int> >e[N];
void add_edge(int x,int y,int v){
	e[x].push_back({y,v});
}
void tomin(int&x,int y){
	if(x>y)x=y;
}
void dfs(int x,int fa){
	f[x][1][1]=0;
	for(auto t:e[x]){
		int y=t.to,w=t.val;
		if(y==fa)continue;
		dfs(y,x);
		memset(g,INF,sizeof g);
		for(int i=0;i<3;i++)
			for(int j=0;j<3-i;j++)
				for(int kx=0;kx<2;kx++)
					for(int ky=0;ky<2;ky++)
						tomin(g[i+j][kx],f[x][i][kx]+f[y][j+ky][ky]+w),
						tomin(g[i+j][0 ],f[x][i+kx][kx]+f[y][j][ky]+(w^1));
		memcpy(f[x],g,sizeof g);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add_edge(x,y,0),add_edge(y,x,1);
	}
	memset(f,INF,sizeof f);
	dfs(1,0);
	int ans=INF;
	for(int i=0;i<6;i++)
		tomin(ans,f[1][i/2][i&1]);
	cout<<ans<<"\n";
}