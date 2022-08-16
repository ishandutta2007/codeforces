#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
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

const int MaxN=200010;

int n;
int v[MaxN];

void add(int x,int p)
{
	for (;x<MaxN;x+=x&-x)
		v[x]+=p;
}

int get(int x)
{
	int p=0;
	for (;x;x-=x&-x)
		p+=v[x];
	return p;
}

int main()
{
	int T;
	cin>>T;
	ld sum=0;
	n=1;
	while (T--)
	{
		int flag;
		scanf("%d",&flag);
		if (flag==1)
		{
			int a,x;
			scanf("%d%d",&a,&x);
			sum+=(ld)a*x;
			add(1,x);
			add(a+1,-x);
		}
		else if (flag==2)
		{
			int k;
			scanf("%d",&k);
			++n;
			sum+=k;
			add(n,k);
			add(n+1,-k);
		}
		else
		{
			int t=get(n);
			add(n,-t);
			add(n+1,t);
			sum-=t;
			--n;
		}
		printf("%.10lf\n",(double)(sum/n));
	}
	return 0;
}