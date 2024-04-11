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
const int mod = 1e9+7;
inline void add(int &a,const int &b){a+=b;if(a>=mod)a-=mod;}

int n,m;
int C[maxn][maxn];
int f[maxn];

bitset<maxn>a[maxn],base[maxn],M;
bool v[maxn];
char str[maxn];

int main()
{
	C[0][0]=1;
	for(int i=1;i<maxn;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	f[0]=1;
	for(int i=1;i<maxn;i++)
	{
		for(int j=0;j<i;j++)
			add(f[i],(ll)C[i-1][j]*f[i-1-j]%mod);
	}
	
	scanf("%d%d",&m,&n); M.set();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
			if(str[j]=='1') a[i][j]=1;
	}
	for(int i=1;i<=m;i++)
	{
		base[i]=M;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]) base[i]&=a[j];
			else base[i]&=(a[j]^M);
		}
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++) printf("%d",base[i][j]?1:0);
		puts("");
	}*/
	int re=1;
	for(int i=1;i<=m;i++)
	{
		int num=0;
		for(int j=i;j<=m;j++) if(base[i][j]&&!v[j])
			num++,v[j]=true;
		re=(ll)re*f[num]%mod;
	}
	printf("%d\n",re);
	
	return 0;
}