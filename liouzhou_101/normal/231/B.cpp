#include<cstdio>
#include<iostream>
#include<bitset>

using namespace std;

int L;
bitset<20010> F[110];

void print(int N,int D)
{
	if (!N) return;
	for (int i=1;i<=L;++i)
		if (!(N&1))
		{
			if (D+i<=20000)
			if (F[N-1][D+i])
			{
				print(N-1,D+i);
				printf("%d ",i);
				return;
			}
		}
		else
		{
			if (D-i>=0)
			if (F[N-1][D-i])
			{
				print(N-1,D-i);
				printf("%d ",i);
				return;
			}
		}
}

int main()
{
	int N,D;
	cin>>N>>D>>L;
	F[0][10000]=1;
	for (int i=0;i<N;++i)
	{
		for (int j=1;j<=L;++j)
		{
			if (i&1)
				F[i+1]|=F[i]>>j;
			else
				F[i+1]|=F[i]<<j;
		}
	}
	if (!F[N][D+10000])
	{
		puts("-1");
		return 0;
	}
	print(N,D+10000);
	return 0;
}