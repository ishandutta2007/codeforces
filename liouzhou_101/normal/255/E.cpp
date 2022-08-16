#include<cstdio>
#include<cmath>
#include<iostream>
#include<map>

using namespace std;

map<int,int> F[1000010];

void init()
{
	for (int i=2;i<=1000000;++i)
	{
		int R=sqrt(i);
		int L=sqrt(R);
		if (L*L*L*L<i) ++L;
		int x=0;
		F[i]=F[i-1];
		for (;F[R][x]-F[L-1][x];++x);
		F[i][x]++;
	}
}

void work()
{
	int n;
	cin>>n;
	int ans=0;
	while (n--)
	{
		long long x;
		scanf("%I64d",&x);
		long long R=sqrt(x);
		long long L=sqrt(R);
		if (L*L*L*L<x) ++L;
		int p=0;
		for (;F[R][p]-F[L-1][p];++p);
		ans^=p;
	}
	puts(ans?"Furlo":"Rublo");
}

int main()
{
	init();
	work();
	return 0;
}