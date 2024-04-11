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
#define inf 1e9
using namespace std;

const int maxn = 1100;

int n,m,k;
struct point
{
	int a[5];
}p[maxn],ep[maxn][maxn];
bool v[maxn];

bool clac(point &x,point &y)
{
	int re=0;
	for(int i=1;i<=5;i++) re+=x.a[i]*y.a[i];
	return re>0;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++) scanf("%d",&p[i].a[j]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(i!=j)
		{
			for(int k=1;k<=5;k++) ep[i][j].a[k]=p[j].a[k]-p[i].a[k];
		}
	
	if(n>243) puts("0");
	else
	{
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=n;j++) if(i!=j)
			{
				for(int k=1;k<=n;k++) if(k!=i&&k!=j)
				{
					if(clac(ep[i][j],ep[i][k])) 
					{ 
						v[i]=true; break; 
					}
				}
				if(v[i]) break;
			}
		}
		int re=0;
		for(int i=1;i<=n;i++) if(!v[i]) re++;
		printf("%d\n",re);
		for(int i=1;i<=n;i++) if(!v[i]) printf("%d\n",i);
	}
	
	return 0;
}