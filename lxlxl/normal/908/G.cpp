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

const int maxn = 710;
const int mod = 1e9+7;
inline void add(int &a,const int &b){a+=b;if(a>=mod)a-=mod;}
inline void dec(int &a,const int &b){a-=b;if(a<0) a+=mod;}

int pw[maxn];

int n,a[maxn];
int f[2][maxn][2],g[11][maxn],x;
void cal()
{
	memset(f,0,sizeof f); int now=0;
	f[now][0][1]=1;
	for(int i=0;i<n;i++)
	{
		now=!now;
		for(int j=0;j<=i;j++) for(int k=0;k<2;k++) if(f[!now][j][k])
		{
			int &tmp=f[!now][j][k];
			int u=k?a[i+1]:9;
			for(int l=0;l<=u;l++)
			{
				if(l>=x) add(f[now][j+1][k&(l==u)],tmp);
				else add(f[now][j][k&(l==u)],tmp);
			}
			tmp=0;
		}
	}
	for(int i=n;i>=1;i--) 
		add(g[x][i],(f[now][i][0]+f[now][i][1])%mod),
		add(g[x][i],g[x][i+1]);
}
char str[maxn];

int re;

int main()
{
	pw[0]=1; for(int i=1;i<maxn;i++) pw[i]=(ll)pw[i-1]*10ll%mod;
	
	scanf("%s",str+1); n=strlen(str+1);
	for(int i=1;i<=n;i++) a[i]=str[i]-'0';
	
	for(x=1;x<10;x++) cal();
	for(int i=1;i<10;i++) 
		for(int j=1;j<=n;j++) dec(g[i][j],g[i+1][j]);
	
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<=n;j++) add(re,(ll)g[i][j]*i%mod*pw[j-1]%mod);
	}
	printf("%d\n",re);
	
	return 0;
}