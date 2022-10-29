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

const int maxn = 410000;
const int mod  = 1e9+7;

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1)
		re=(ll)re*x%mod;
	return re;
}
int inv(int x){ return pw(x,mod-2); }

int s[maxn],invs[maxn];
void pre()
{
	s[0]=1; for(int i=1;i<maxn;i++) s[i]=(ll)s[i-1]*i%mod;
	invs[maxn-1]=inv(s[maxn-1]);
	for(int i=maxn-2;i>=0;i--) invs[i]=(ll)invs[i+1]*(i+1)%mod;
}
int C(int i,int j){ return (ll)s[i]*invs[j]%mod*invs[i-j]%mod; }
int cal(int n,int k)
{
	if(n<k) return 0;
	int re=0;
	for(int i=0,sig=1;i<=k;i++,sig=-sig)
		(re+=(ll)sig*C(k,i)*pw(k-i,n)%mod)%=mod;
	(re+=mod)%=mod;
	return (ll)re*invs[k]%mod;
}

int n,k;


int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	pre();
	
	scanf("%d%d",&n,&k);
	int c=0;
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		(c+=x)%=mod;
	}
	int c2=(cal(n,k)+(ll)(n-1)*cal(n-1,k)%mod)%mod;
	printf("%lld\n",(ll)c*c2%mod);
	
	return 0;
}