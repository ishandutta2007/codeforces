#include<bits/stdc++.h>
using namespace std;
const int N=59;
char c[N][N];
int n,m;
bool vst[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool ok(int x,int y){return x>0&&x<=n&&y>0&&y<=m;}
struct node{int x,y;};
int main(){
	int T; cin>>T;
	while(T--){
		cin>>n>>m;
		int gcnt=0;
		for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
		bool ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(c[i][j]=='G') gcnt++;
				if(c[i][j]!='B') continue;
				for(int k=0;k<4;k++){
					int x=i+dx[k],y=j+dy[k];
					if(ok(x,y)){
						if(c[x][y]=='G') ans=0;
						else if(c[x][y]!='B') c[x][y]='#';
					}
				}
			}
		}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=m;j++) cout<<c[i][j];
	//		puts("");
	//	}
		if(!gcnt){puts("Yes");continue;}
		if(!ans){puts("No");continue;}
		memset(vst,0,sizeof(vst));
		queue<node>q; q.push((node){n,m}); vst[n][m]=1;
		if(c[n][m]=='#'){puts("No");continue;}
		while(!q.empty()){
			int x=q.front().x,y=q.front().y; q.pop();
			for(int k=0;k<4;k++){
				int cx=x+dx[k],cy=y+dy[k];
				if(ok(cx,cy)&&!vst[cx][cy]&&c[cx][cy]!='#'){
					q.push((node){cx,cy});
					vst[cx][cy]=1;
				}
			}
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
			if(c[i][j]=='G'&&!vst[i][j]) ans=0;
		if(ans) puts("Yes");
		else puts("No");
	}
	return 0;
}