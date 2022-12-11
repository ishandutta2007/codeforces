#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

char a[2001][2002];
int f[2001][2001];
struct dn{int x,y;};
vector<dn>g[2];
int z[4001];
bool inq[2001][2001];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		f[0][i]=f[i][0]=2e9;
	f[0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=min(f[i-1][j],f[i][j-1])+(a[i][j]!='a');
	int w=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]<=k)w=max(w,i+j);
	if(w==0)g[0].push_back((dn){1,1}),inq[1][1]=1;
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(f[i][j]<=k&&i+j==w)g[0].push_back((dn){i,j}),inq[i][j]=1,a[i][j]='a';
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
///			printf("%d\n",f[i][j]);
//	printf("%d %d\n",g[0][0].x,g[0][0].y);
	for(int o=0;;o^=1){
		if(!g[o].size())break;
		int c='z';
		for(int i=0;i<g[o].size();i++)
			c=min(c,(int)a[g[o][i].x][g[o][i].y]);
		z[++z[0]]=c;
		for(int i=0;i<g[o].size();i++)if(c==a[g[o][i].x][g[o][i].y]){
			for(int w=0;w<2;w++){
				int x=g[o][i].x,y=g[o][i].y;
				if(w)x++;
				else y++;
				if(!x||x>n||!y||y>n||inq[x][y])continue;
				inq[x][y]=1;
				g[o^1].push_back((dn){x,y});
			}
		}
		g[o].clear();
	}
	for(int i=1;i<=w-2;i++)printf("a");
	for(int i=1;i<=z[0];i++)
		printf("%c",z[i]);
	printf("\n");
}