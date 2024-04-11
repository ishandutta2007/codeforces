#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const int INF=1000000000;
int n,m,sx,sy,tx[10],ty[10],tp[10],tn,bx[10],by[10],bn;
int f[21][21][256][256],pr[256],ans;
int qx[2000010],qy[2000010],qt[2000010],qb[2000010],l,r;
char a[51][51];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='S') sx=i,sy=j;
			if(a[i][j]>='0'&&a[i][j]<='9') tx[a[i][j]-'0']=i,ty[a[i][j]-'0']=j,tn++;
			if(a[i][j]=='B') bx[++bn]=i,by[bn]=j;
		}
	for(int i=1;i<=tn;i++) scanf("%d",&tp[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<(1<<tn);k++)
				for(int l=0;l<(1<<bn);l++)
					f[i][j][k][l]=INF;
	l=r=1;
	qx[1]=sx,qy[1]=sy,qt[1]=0,qb[1]=0;
	f[sx][sy][0][0]=0;
	while(l<=r)
	{
		int ox=qx[l],oy=qy[l],ot=qt[l],ob=qb[l++];
		for(int k=0;k<4;k++)
		{
			int nx=ox+dx[k],ny=oy+dy[k],nt=ot,nb=ob;
			if(a[nx][ny]!='.'&&a[nx][ny]!='S') continue;
			for(int i=1;i<=tn;i++)
			{
				if(ny<=ty[i]) continue;
				if(nx==tx[i]-1&&ox==tx[i]) nt^=(1<<(i-1));
				if(ox==tx[i]-1&&nx==tx[i]) nt^=(1<<(i-1));
			}
			for(int i=1;i<=bn;i++)
			{
				if(ny<=by[i]) continue;
				if(nx==bx[i]-1&&ox==bx[i]) nb^=(1<<(i-1));
				if(ox==bx[i]-1&&nx==bx[i]) nb^=(1<<(i-1));
			}
			if(f[nx][ny][nt][nb]>f[ox][oy][ot][ob]+1)
				f[nx][ny][nt][nb]=f[ox][oy][ot][ob]+1,qx[++r]=nx,qy[r]=ny,qt[r]=nt,qb[r]=nb;
		}
	}
	for(int i=0;i<(1<<tn);i++)
		for(int j=1;j<=tn;j++)
			if(i&(1<<(j-1))) pr[i]+=tp[j];
	for(int i=0;i<(1<<tn);i++)
		ans=max(ans,pr[i]-f[sx][sy][i][0]);
	printf("%d\n",ans);
	return 0;
}