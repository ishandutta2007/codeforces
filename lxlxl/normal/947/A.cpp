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

const int maxn = 1e6+10;

int p[maxn],pri,mp[maxn];
void pre()
{
	for(int i=2;i<maxn;i++)
	{
		if(!mp[i]) p[++pri]=i,mp[i]=i;
		for(int j=1,k=p[j]*i;k<maxn;j++,k=p[j]*i)
		{
			mp[k]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int n,f[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	pre();
	for(int i=2;i<maxn;i++)
	{
		f[i]=i;
		if(mp[i]!=i)
		{
			int t=i;
			while(t>1)
			{
				int pi=mp[t];
				while(t%pi==0) t/=pi;
				f[i]=min(f[i],i-pi+1);
			}
		}
	}
	scanf("%d",&n); int t=n,kk=n;
	while(t>1)
	{
		int pi=mp[t];
		while(t%pi==0) t/=pi;
		kk=min(kk,n-pi+1);
	}
	int ans=n;
	for(int i=kk;i<n;i++) ans=min(ans,f[i]);
	printf("%d\n",ans);
	
	return 0;
}