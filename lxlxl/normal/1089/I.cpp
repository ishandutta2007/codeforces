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

const int maxn = 405;

int n,mod;
inline void add(int &a,const int &b){ a+=b;if(a>=mod)a-=mod; }
inline void dec(int &a,const int &b){ a-=b;if(a<0) a+=mod; }

int s[maxn];
int f[maxn],ans[maxn];
int g[maxn][maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	int Tcase; scanf("%d%d",&Tcase,&mod);
	
	s[0]=1; for(int i=1;i<maxn;i++) s[i]=(ll)s[i-1]*i%mod;
	f[1]=1;
	for(int i=2;i<maxn;i++)
	{
		f[i]=s[i];
		for(int j=1;j<i;j++) dec(f[i],(ll)f[j]*s[i-j]%mod);
	}
	g[0][0]=1;
	for(int i=1;i<maxn;i++) for(int j=1;j<=i;j++)
	{
		for(int k=j-1;k<i;k++) add(g[i][j],(ll)g[k][j-1]*s[i-k]%mod);
	}
	
	ans[1]=1;
	for(int i=2;i<maxn;i++)
	{
		ans[i]=s[i];
		for(int j=1;j<i;j++) if(i-j>1||j>1)
			dec(ans[i],2ll*f[j]%mod*s[i-j]%mod);
		for(int k=3;k<i;k++) dec(ans[i],(ll)g[i][k]*ans[k]%mod);
	}
	
	while(Tcase--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	
	return 0;
}