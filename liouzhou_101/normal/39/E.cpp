#include<cstdio>
#include<iostream>

using namespace std;

const int MaxA=50010;
const int MaxB=35;

int a,b;
long long n;
long long v[MaxA][MaxB];

int u[MaxA][MaxB],F[MaxA][MaxB];

int solve(int a,int b)
{
	if (u[a][b]) return F[a][b];
	u[a][b]=1;
	if (v[a][b]==n) return F[a][b]=1;
	if (b>30) return F[a][b]=2;
	if (a>=40000) return F[a][b]=(n-40000+1)&1;
	int x=solve(a+1,b);
	int y=solve(a,b+1);
	if (!x||!y)
		F[a][b]=1;
	else if (x==2||y==2)
		F[a][b]=2;
	return F[a][b];
}

int main()
{
	cin>>a>>b>>n;
	for (int i=1;i<MaxA;++i)
		for (int j=v[i][0]=1;j<MaxB;++j)
			v[i][j]=min(v[i][j-1]*i,n);
	int p=solve(a,b);
	if (p==0)
		puts("Stas");
	else if (p==1)
		puts("Masha");
	else
		puts("Missing");
	return 0;
}