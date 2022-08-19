#include <bits/stdc++.h>
#define MX 360
#define SIZE 22
using namespace std;
typedef pair <int,int> P;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool ng[SIZE][MX][4];
bool use[SIZE][MX];
char str[4];

void solve(){
	memset(ng,false,sizeof(ng));
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&str);
		if(str[0]=='C'){
			int r,a,b;
			scanf("%d%d%d",&r,&a,&b);
			for(int j=a;j!=b;j=(j+1)%MX){
				ng[r-1][j][1]=true;
				ng[r][j][3]=true;
			}
		} else{
			int r1,r2,a;
			scanf("%d%d%d",&r1,&r2,&a);
			for(int j=r1;j!=r2;j++){
				ng[j][(a-1+MX)%MX][0]=true;
				ng[j][a][2]=true;
			}
		}
	}
	memset(use,false,sizeof(use));
	queue <P> que;
	que.push(P(0,0));
	use[0][0]=true;
	while(!que.empty()){
		P p=que.front();que.pop();
		for(int i=0;i<4;i++){
			if(ng[p.first][p.second][i]) continue;
			int x=p.first+dy[i],y=(p.second+dx[i]+MX)%MX;
			if(x>=0&&x<SIZE&&!use[x][y]){
				use[x][y]=true;
				que.push(P(x,y));
			}
		}
	}
	puts(use[SIZE-1][0]?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
}