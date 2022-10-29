#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 2100;

int n,r;
int xi[maxn];

long double yi[maxn];

int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++) scanf("%d",&xi[i]);
	
	for(int i=1;i<=n;i++)
	{
		long double tmp=(long double)r;
		for(int j=1;j<i;j++)
		{
			if(abs(xi[j]-xi[i])<=2*r)
			{
				int tc=abs(xi[j]-xi[i]);
				int cc=4*r*r-tc*tc;
				tmp=max(tmp,yi[j]+sqrt((long double)cc));
			}
		}
		yi[i]=tmp;
	}
	for(int i=1;i<=n;i++) printf("%.11Lf ",yi[i]);
	
    return 0;
}