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

const int maxn = 1100;

int n;
int a[maxn];


int main()
{
	scanf("%d",&n); int m=2*n;
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	int ans=INT_MAX;
	for(int i=1;i<m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			int last=-1,ct=0;
			for(int k=1;k<=m;k++) if(k!=i&&k!=j)
			{
				if(last==-1) last=a[k];
				else ct+=abs(a[k]-last),last=-1;
			}
			ans=min(ans,ct);
		}
	}
	printf("%d\n",ans);
	
	return 0;
}