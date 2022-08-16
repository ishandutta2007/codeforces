#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

const int MOD=1000000007;

int v[110];
long long F[110],s[110];
long long C[110][110];

long long power(long long x,long long p)
{
	if (!p) return 1;
	long long t=power(x,p>>1);
	t=t*t%MOD;
	if (p&1) t=t*x%MOD;
	return t;
}

int a[110];

long long ans;

void DFS(int k,int h,long long p)
{
	if (k==7)
	{
		ans=(ans+s[h+1]*p)%MOD;
		return;
	}
	for (int i=0;i<=10;++i)
	{
		F[i]--;
		DFS(k+1,h+i,p*(F[i]+1)%MOD);
		F[i]++;
	}
}

int main()
{
	for (int i=0;i<=100;++i)
		C[i][0]=1;
	for (int i=1;i<=100;++i)
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	int m;
	cin>>m;
	for (int i=1;i<=10;++i)
	{
		v[i]=m%10;
		m/=10;
	}
	int have=0;
	for (int i=10;i>=1;--i)
	{
		for (int j=0;j<v[i];++j)
		{
			int p=(j==4||j==7);
			for (int k=0;k<=10;++k) if (i-1-k>=0)
				F[have+p+k]+=C[i-1][k]*power(2,k)*power(8,i-1-k);
		}
		have+=(v[i]==4||v[i]==7);
	}
	F[have]+=1;
	F[0]--;
	for (int i=10;i>=0;--i)
		s[i]=s[i+1]+F[i];
	DFS(1,0,1);
	cout<<ans<<endl;
	return 0;
}