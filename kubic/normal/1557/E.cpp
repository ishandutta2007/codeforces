#include <bits/stdc++.h>
using namespace std;
#define N 55
const int INF=1e9;
const int X[]={0,1,0,-1,0,1,1,-1,-1},Y[]={0,0,1,0,-1,1,-1,1,-1}; 
int T,n,nwX,nwY,w,ps;
bool vs[N],z[N][N],tmp[N][N];char a[N];
void move(int x,int y)
{nwX=x;nwY=y;printf("%d %d\n",x,y);fflush(stdout);}
int qry()
{
	scanf("%s",a);
	if(a[0]=='L') return 4;
	if(a[0]=='R') return 2;
	if(a[0]=='D')
	{
		if(a[2]=='n') return INF;
		if(a[4]=='-')
		{
			if(a[5]=='L') return 6;
			return 5;
		}return 1;
	}
	if(a[0]=='U')
	{
		if(a[2]=='-')
		{
			if(a[3]=='L') return 8;
			return 7;
		}return 3;
	}return -1;
}
bool upd(int w)
{
	if(w==INF) return 1;
	for(int i=1;i<=8;++i) vs[i]=0;
	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
			tmp[i][j]=0;
	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
			tmp[i+X[w]][j+Y[w]]=z[i][j];
	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
		{
			z[i][j]=0;
			if(i==nwX || j==nwY) continue;
			if(i+j==nwX+nwY) continue;
			if(i-j==nwX-nwY) continue;
			z[i][j]=tmp[i][j];vs[i]|=z[i][j];
		}return 0;
}
void slv()
{
	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
			z[i][j]=1;
	move(1,1);
	while(1)
	{
		w=qry();if(upd(w)) return;ps=0;
		if(vs[nwX+1])
		{
			for(int i=1;i<=8;++i)
				if(z[nwX+1][i]) ps=i;
			move(nwX,ps);
		}
		else
		{
			for(int i=nwX+1;i<=8;++i)
				if(vs[i]) {move(i-1,nwY);break;}
		}
	}
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}