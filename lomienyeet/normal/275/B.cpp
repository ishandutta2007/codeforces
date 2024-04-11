#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int MAXN=1e2+5;
char grid[MAXN][MAXN];
int visited[MAXN][MAXN];
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
struct node{
	int u,v,to,dir;
};
void solve(){
	int N,M,cnt=0;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>grid[i];
		for(int j=0;j<M;j++){
			if(grid[i][j]=='B')cnt++;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(grid[i][j]=='B'){
				int res=0;
				memset(visited,-1,sizeof(visited));
				queue<node> Q;
				Q.push((node){i,j,0,-1});
				visited[i][j]=0;
				while(Q.size()){
					node n=Q.front();
					Q.pop();
					for(int k=0;k<4;k++){
						int xs=n.u+dirx[k];
						int ys=n.v+diry[k];
						if((visited[xs][ys]==-1||visited[xs][ys]>=n.to)&&grid[xs][ys]=='B'){
							if(n.dir==-1||k==n.dir){
								node fuck={xs,ys,n.to,k};
								Q.push(fuck);
								visited[xs][ys]=n.to;
							}
							else if(n.to<1){
								node fuck={xs,ys,n.to+1,k};
								Q.push(fuck);
								visited[xs][ys]=n.to+1;
							}
						}
					}
				}
				
					for(int k=0;k<N;k++){
						for(int l=0;l<M;l++){
							if(visited[k][l]!=-1)res++;
						}
					}
					if(cnt!=res){
						cout<<"NO\n";
						return;
					}
			}
		}
	}
	cout<<"YES\n";
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)solve();
}