#include <bits/stdc++.h>
using namespace std;
#define N 105
#define M 55 
int n,m,cnt,ps[N],ans[N];bool tg[N];char a[N][M];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i) if(!ps[i])
	{
		tg[i]=1;for(int j=1;j<=m;++j) if(a[i][j]!=a[i][m-j+1]) tg[i]=0;
		for(int j=1;j<=n;++j) if(i!=j)
		{
			bool fl=1;
			for(int k=1;k<=m;++k) if(a[i][k]!=a[j][m-k+1]) {fl=0;break;}
			if(fl) {ps[i]=j,ps[j]=i;break;}
		}if(ps[i]) ans[++ans[0]]=i;
	}cnt=ans[0];
	for(int i=1;i<=n;++i) if(tg[i] && !ps[i]) {ans[++ans[0]]=i;break;}
	for(int i=cnt;i>=1;--i) ans[++ans[0]]=ps[ans[i]];printf("%d\n",ans[0]*m);
	for(int i=1;i<=ans[0];++i) for(int j=1;j<=m;++j) printf("%c",a[ans[i]][j]);
	return 0;
}