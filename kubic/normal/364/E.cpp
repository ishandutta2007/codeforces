#include <bits/stdc++.h>
using namespace std;
#define N 2505
#define ll long long
int n,m,c,z1[N],z2[N],tmp[N],nxt[N][N][4];ll ans;bool a[N][N];char a1[N];
void slv(int x1,int y1,int x2,int y2)
{
	if(x1==x2 && y1==y2) {if(a[x1][y1]==c) ++ans;return;}
	if(x2-x1>y2-y1)
	{
		int mid=(x1+x2)/2;
		for(int i=y1;i<=y2;++i)
		{
			z1[0]=mid;z2[0]=mid+1;for(int j=1;j<=c+1;++j) z1[j]=x1-1,z2[j]=x2+1;
			for(int j=i;j<=y2;++j)
			{
				for(int k=1,x=nxt[mid][j][0],t=1;k<=c+1;++k,x=x?nxt[x-1][j][0]:0)
				{
					while(t<=c+1 && tmp[0]<=c && z1[t]>x) tmp[++tmp[0]]=z1[t++];
					if(tmp[0]>c) break;tmp[++tmp[0]]=x;
				}tmp[0]=0;for(int k=1;k<=c+1;++k) z1[k]=tmp[k];
				for(int k=1,x=nxt[mid+1][j][1],t=1;k<=c+1;++k,x=x<n?nxt[x+1][j][1]:n+1)
				{
					while(t<=c+1 && tmp[0]<=c && z2[t]<x) tmp[++tmp[0]]=z2[t++];
					if(tmp[0]>c) break;tmp[++tmp[0]]=x;
				}tmp[0]=0;for(int k=1;k<=c+1;++k) z2[k]=tmp[k];
				for(int k=0;k<=c;++k) ans+=(z1[k]-z1[k+1])*(z2[c-k+1]-z2[c-k]);
			}
		}slv(x1,y1,mid,y2);slv(mid+1,y1,x2,y2);
	}
	else
	{
		int mid=(y1+y2)/2;
		for(int i=x1;i<=x2;++i)
		{
			z1[0]=mid;z2[0]=mid+1;for(int j=1;j<=c+1;++j) z1[j]=y1-1,z2[j]=y2+1;
			for(int j=i;j<=x2;++j)
			{
				for(int k=1,y=nxt[j][mid][2],t=1;k<=c+1;++k,y=y?nxt[j][y-1][2]:0)
				{
					while(t<=c+1 && tmp[0]<=c && z1[t]>y) tmp[++tmp[0]]=z1[t++];
					if(tmp[0]>c) break;tmp[++tmp[0]]=y;
				}tmp[0]=0;for(int k=1;k<=c+1;++k) z1[k]=tmp[k];
				for(int k=1,y=nxt[j][mid+1][3],t=1;k<=c+1;++k,y=y<m?nxt[j][y+1][3]:m+1)
				{
					while(t<=c+1 && tmp[0]<=c && z2[t]<y) tmp[++tmp[0]]=z2[t++];
					if(tmp[0]>c) break;tmp[++tmp[0]]=y;
				}tmp[0]=0;for(int k=1;k<=c+1;++k) z2[k]=tmp[k];
				for(int k=0;k<=c;++k) ans+=(z1[k]-z1[k+1])*(z2[c-k+1]-z2[c-k]);
			}
		}slv(x1,y1,x2,mid);slv(x1,mid+1,x2,y2);
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&c);
	for(int i=1;i<=n;++i) {scanf("%s",a1+1);for(int j=1;j<=m;++j) a[i][j]=a1[j]-'0';}
	for(int i=1;i<=n;++i) nxt[i][m+1][3]=m+1;for(int i=1;i<=m;++i) nxt[n+1][i][1]=n+1;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(a[i][j]) nxt[i][j][0]=i,nxt[i][j][2]=j;
		else nxt[i][j][0]=nxt[i-1][j][0],nxt[i][j][2]=nxt[i][j-1][2];
	for(int i=n;i;--i) for(int j=m;j;--j) if(a[i][j]) nxt[i][j][1]=i,nxt[i][j][3]=j;
		else nxt[i][j][1]=nxt[i+1][j][1],nxt[i][j][3]=nxt[i][j+1][3];slv(1,1,n,m);
	printf("%lld\n",ans);return 0;
}