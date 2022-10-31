#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAXN 100
using namespace std;
int n,nxt[MAXN+10],dist[MAXN+10][MAXN+10],dcnt,dfn[MAXN+10];
long long ans=1;
bool vis[MAXN+10];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
void floyd(){
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main()
{
	Read(n);
	int i,j,k;
	memset(dist,0x3f,sizeof dist);
	for(i=1;i<=n;i++)
		Read(nxt[i]);
	for(i=1;i<=n;i++){
		if(!vis[i]){
			int u=i,cnt=0;
			while(!vis[u]){
				vis[u]=1,cnt++;
				u=nxt[u];
			}
			if(u!=i){
				puts("-1");
				return 0;
			}
			if(!(cnt&1))
				cnt>>=1;
			ans=ans/__gcd(ans,1ll*cnt)*cnt;
		}
	}
	printf("%I64d\n",ans);
}