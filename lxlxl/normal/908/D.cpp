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

const int mod = 1e9+7;
const int maxn = 2100;
inline void add(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
int sqr(int x){return (ll)x*x%mod;}

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1)
		re=(ll)re*x%mod;
	return re;
}
int inv(int x){return pw(x,mod-2);}

int n,k,p,q;
int f[maxn][maxn];

int main()
{
	scanf("%d%d%d",&k,&p,&q);
	n=inv(p+q); p=(ll)p*n%mod,q=(ll)q*n%mod;
	
	f[1][0]=1;
	int re=0;
	for(int i=1;i<=k*2;i++)
	{
		for(int j=0;j<=k;j++) if(f[i][j])
		{
			int tmp=f[i][j];
			if(i+j<k)
			{
				add(f[i+1][j],(ll)tmp*p%mod);
				add(f[i][i+j],(ll)tmp*q%mod);
			}
			else
			{
				int cc=(i+j+(ll)p*inv(1-p+mod)%mod)%mod;
				cc=(ll)cc*inv(1-p+mod)%mod;
				add(re,(ll)tmp*q%mod*cc%mod);
			}
		}
	}
	printf("%d\n",re);
	
    return 0;
}