#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int DIRE[2][4]={
	{1,0,-1,0},
	{0,1,0,-1}
},DIRE2[2][8]={
	{1,1,1,0,0,-1,-1,-1},
	{-1,0,1,-1,1,-1,0,1}
};
int n,m;
char s[30][30];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		memset(s,'0',sizeof(s));
		int x=1,y=1;
		for(int i=0; i<4;){
			bool b=0;
			for(int j=0; j<8; j++){
				int nx=x+DIRE2[0][j],ny=y+DIRE2[1][j];
				if(s[nx][ny]=='1') b=1;
			}
			if(!b) s[x][y]='1';
			int nx=x+DIRE[0][i],ny=y+DIRE[1][i];
			if(nx<1||nx>n||ny<1||ny>m) i++;
			else x=nx,y=ny;
		}
		for(int i=1; i<=n; i++)
			s[i][m+1]=0,puts(s[i]+1);
		puts("");
	}
	return 0;
}