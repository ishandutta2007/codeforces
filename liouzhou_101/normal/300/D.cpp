#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MOD=7340033;

int F[32][1010];
int tmp1[1010],tmp2[1010];

void calc(int *p,int *a)
{
	for (int i=0;i<=1000;++i)
		p[i]=0;
	for (int i=0;i<=1000;++i)
		for (int j=0;j<=i;++j)
			p[i]=(p[i]+(ll)a[j]*a[i-j])%MOD;
}

void init()
{
	F[0][0]=1;
	for (int i=1;i<=30;++i)
	{
		calc(tmp1,F[i-1]);
		calc(tmp2,tmp1);
		for (int j=1;j<=1000;++j)
			F[i][j]=tmp2[j-1];
		F[i][0]=1;
	}
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int t=0;
		while (1)
		{
			if (n%2==1&&n>2)
			{
				n/=2;
				++t;
			}
			else
				break;
		}
		printf("%d\n",F[t][k]);
	}
}

int main()
{
	init();
	work();
	return 0;
}