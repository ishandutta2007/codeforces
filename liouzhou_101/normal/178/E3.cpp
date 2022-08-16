#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=2010;

int n;
int a[MaxN][MaxN],s[MaxN][MaxN],v[MaxN][MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n+2;++i)
		for (int j=1;j<=n+2;++j)
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			s[i][j]=a[i+2][j+2]-a[i+2][max(j-3,0)]-a[max(i-3,0)][j+2]+a[max(i-3,0)][max(j-3,0)];
			if (s[i][j]>=13)
				s[i][j]=1;
			else if (s[i][j]<=7)
				s[i][j]=0;
			else
				s[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
		}
}

int circle,square;
int head,tail,Qx[MaxN*MaxN],Qy[MaxN*MaxN];

int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

void check(int sx,int sy)
{
	head=tail=1;
	v[Qx[1]=sx][Qy[1]=sy]=1;
	pair<int,int> S=make_pair(sx,sy);
	while (head<=tail)
	{
		int nx=Qx[head],ny=Qy[head];
		++head;
		for (int k=0;k<4;++k)
		{
			int tx=nx+dx[k],ty=ny+dy[k];
			if (s[tx][ty]&&!v[tx][ty])
			{
				++tail;
				v[Qx[tail]=tx][Qy[tail]=ty]=1;
				S=min(S,make_pair(tx,ty));
			}
		}
	}
	if (tail<100) return;
	int dis=-1;
	for (int i=1;i<=tail;++i)
	{
		int tdis=(S.first-Qx[i])*(S.first-Qx[i])+(S.second-Qy[i])*(S.second-Qy[i]);
		if (tdis>dis) dis=tdis;
	}
	if (dis*0.67<tail)
		++circle;
	else
		++square;
}

void work()
{
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			if (v[i][j]) continue;
			if (!s[i][j]) continue;
			check(i,j);
		}
	cout<<circle<<" "<<square<<endl;
}

int main()
{
	init();
	work();
	return 0;
}