#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define LD long double
#define N 2005

int n,m,goin[N][N];
char s[N][N];
queue<int> qx,qy;

void exitout(){
	puts("Not unique");
	exit(0);
}

inline void bash(int x,int y){
	if(s[x-1][y]=='.'){
		goin[x-1][y]--;
		if(goin[x-1][y]==1) qx.push(x-1),qy.push(y);
	}
	if(s[x+1][y]=='.'){
		goin[x+1][y]--;
		if(goin[x+1][y]==1) qx.push(x+1),qy.push(y);
	}
	if(s[x][y-1]=='.'){
		goin[x][y-1]--;
		if(goin[x][y-1]==1) qx.push(x),qy.push(y-1);
	}
	if(s[x][y+1]=='.'){
		goin[x][y+1]--;
		if(goin[x][y+1]==1) qx.push(x),qy.push(y+1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='.'){
		if(s[i-1][j]=='.') goin[i-1][j]++;
		if(s[i+1][j]=='.') goin[i+1][j]++;
		if(s[i][j-1]=='.') goin[i][j-1]++;
		if(s[i][j+1]=='.') goin[i][j+1]++;
	}
	rep(i,1,n) rep(j,1,m) if(goin[i][j]==1)
		qx.push(i),qy.push(j);
	while(!qx.empty()){
		int i=qx.front(),j=qy.front();
		qx.pop(),qy.pop();
		if(s[i-1][j]=='.'){
			s[i][j]='v';
			s[i-1][j]='^';
			bash(i-1,j);
		}
		if(s[i+1][j]=='.'){
			s[i][j]='^';
			s[i+1][j]='v';
			bash(i+1,j);
		}
		if(s[i][j-1]=='.'){
			s[i][j]='>';
			s[i][j-1]='<';
			bash(i,j-1);
		}
		if(s[i][j+1]=='.'){
			s[i][j]='<';
			s[i][j+1]='>';
			bash(i,j+1);
		}
	}
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='.') exitout();
	rep(i,1,n) puts(s[i]+1);
}