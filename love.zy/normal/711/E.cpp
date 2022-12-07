#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lc o << 1
#define rc o << 1 | 1
#define lowbit(x) (x&(-x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

const LL mod=1e6+3;
LL i,j,k,l,m,n;

LL err(LL t)
{
	LL ans=0,tt=1;
	while(tt<=t)
	{
		tt*=2;
		ans+=t/tt;
	}
	return ans;
}

LL errr(int x)
{
	LL ans=0;
	while(x%2==0)
	{
		ans++;
		x/=2;
	}
	return ans;
}

LL pow_mod(LL x,LL y)
{
	LL ans=1;
	while(y>0)
	{
		if(y&1)ans=(ans*x)%mod;
		x=(x*x)%mod;
		y=y>>1;
	}
	return ans;
}

int main()
{
	scanf("%lld%lld",&n,&m);
	if(n<63 && ((LL)1<<n)<m ){printf("1 1");return 0;}
	LL er=0;
	for(i=m-1;i>0;i/=2)er+=i/2;
	LL temp=pow_mod(2,n);
	LL ans=1;
	for(i=1;i<m;i++)
	{
		ans=ans*(temp-i)%mod;
		if(temp-i==0)break;
	}
	LL ha=pow_mod(2,er);
	ans=ans*pow_mod(ha,mod-2)%mod;
	temp=pow_mod(temp,m-1)*pow_mod(ha,mod-2)%mod;
	printf("%lld %lld",(temp-ans+mod)%mod,temp);
    return 0;
}