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
#define ld long double
using namespace std;

const int maxn = 110000;
const int mod = 1e9+9;

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1)
		re=(ll)re*x%mod;
	return re;
}
int inv(int x){ return pw(x,mod-2); }


int cal(int x,int k)
{
	if(x==1) return k;
	return (1ll-pw(x,k)+mod)*inv(1ll-x+mod)%mod;
}

int n,k,a,b,ia,ib;
char str[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d%d%d",&n,&a,&b,&k);
	scanf("%s",str);
	
	int c=(ll)pw(inv(a),k)*pw(b,k)%mod;
	int ans=0;
	for(int i=0;i<=n%k&&i<=n;i++)
	{
		int j=n/k+1;
		int x=str[i]=='+'?1:-1;
		int a1=(ll)pw(a,n-i)*pw(b,i)%mod;
		(ans+=(ll)x*a1*cal(c,j)%mod)%=mod;
	}
	for(int i=n%k+1;i<k&&i<=n;i++)
	{
		int j=n/k;
		int x=str[i]=='+'?1:-1;
		int a1=(ll)pw(a,n-i)*pw(b,i)%mod;
		(ans+=(ll)x*a1*cal(c,j)%mod)%=mod;
	}
	(ans+=mod)%=mod;
	printf("%d\n",ans);
	
    return 0;
}