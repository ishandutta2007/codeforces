#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=60;

int n;
long long k;
int v[MaxN];

long long F[MaxN][2][2];
bool u[MaxN][2][2];

long long solve(int L,int x,int y)
{
	int R=n-L+1;
	if (L>R) return 1;
	if (u[L][x][y]) return F[L][x][y];
	u[L][x][y]=1;
	for (int i=0;i<2;++i) if (v[L]==i||v[L]==-1)
		for (int j=0;j<2;++j) if (v[R]==j||v[R]==-1)
			if ((L<R||i==j)&&(x||i<=j)&&(y||i<=1-j))
				F[L][x][y]+=solve(L+1,x|i<j,y|i<1-j);
	return F[L][x][y];
}

int main()
{
	cin>>n>>k;
	++k;
	for (int i=2;i<=n;++i)
		v[i]=-1;
	if (solve(1,0,0)<k)
	{
		puts("-1");
		return 0;
	}
	for (int i=2;i<=n;++i)
	{
		memset(u,0,sizeof(u));
		memset(F,0,sizeof(F));
		v[i]=0;
		long long t=solve(1,0,0);
		if (t<k)
		{
			k-=t;
			v[i]=1;
		}
	}
	for (int i=1;i<=n;++i)
		putchar(v[i]+'0');
	puts("");
	return 0;
}