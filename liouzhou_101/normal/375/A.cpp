#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=1000010;

int n;
char s[MaxN];
int u[MaxN],c[MaxN];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;++i)
		u[s[i]-'0']++;
	u[1]--;
	u[6]--;
	u[8]--;
	u[9]--;
	c[1]=1;c[2]=6;c[3]=8;c[4]=9;
	int a=0;
	for (int i=1;i<=9;++i)
		for (int j=0;j<u[i];++j)
		{
			printf("%d",i);
			a=(a*10+i)%7;
		}
	while (1)
	{
		int b=a;
		for (int i=1;i<=4;++i)
		{
			b=(b*10+c[i])%7;
		}
		for (int i=1;i<=u[0];++i)
			b=(b*10)%7;
		if (b==0)
		{
			break;
		}
		if (!next_permutation(c+1,c+5)) break;
	}
	for (int i=1;i<=4;++i) printf("%d",c[i]);
	for (int i=0;i<u[0];++i) putchar('0');
	return 0;
}