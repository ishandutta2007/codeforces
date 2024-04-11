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

const int maxn = 110;

int n,m,k;
int a[maxn][maxn];
int c[maxn],s[maxn];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	
	int ans1=0,ans2=0;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++) c[i]=a[i][j];
		for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
		if(!s[n]) continue;
		int mx=-1,pos=-1;
		for(int i=1;i<=n;i++) if(c[i])
		{
			int kk=s[min(n,i+k-1)]-s[i-1];
			if(kk>mx) mx=kk,pos=i;
		}
		ans1+=mx,ans2+=s[pos-1];
	}
	printf("%d %d\n",ans1,ans2);
	
	return 0;
}