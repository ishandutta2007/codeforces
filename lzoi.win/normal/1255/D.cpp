#include<cstdio>
#include<cstring>
const int MAXN=105,MAXK=70;
const int DIRE[2][4]={
	{0,1,0,-1},
	{1,0,-1,0}
};
int n,m,k;
char c[MAXK],s[MAXN][MAXN],ans[MAXN][MAXN];
bool vis[MAXN][MAXN];
int tot,ave;
int main(){
//	freopen("D.in","r",stdin);
	c[1]='0';
	for(int i=2;i<=62;i++){
		if(c[i-1]=='9') c[i]='a';
		else if(c[i-1]=='z') c[i]='A';
		else c[i]=c[i-1]+1;
	}
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
				ans[i][j]=c[k];
				if(s[i][j]=='R') tot++;
			}
		}
		ave=tot/k;
		int x=1,y=0,d=0;
		for(int i=1;i<=k;i++){
			int p=ave;
			if(i+ave*k<=tot) p++;
			while(p){
				int nx=x+DIRE[0][d],ny=y+DIRE[1][d];
				if(nx>n||nx<1||ny>m||ny<1||vis[nx][ny]){
					d=d+1&3;
					nx=x+DIRE[0][d],ny=y+DIRE[1][d];
				}
				if(s[x=nx][y=ny]=='R') p--;
				ans[x][y]=c[i];
				vis[x][y]=1;
//				printf("x %d y %d c %d\n",x,y,i);
			}
		}
		for(int i=1;i<=n;i++)
			ans[i][m+1]=0,puts(ans[i]+1);
	}
	return 0;
}