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

const int maxn = 2100000;
const int Mod = 1e9+7;

int pw(int x,int k)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%Mod) if(k&1)
		re=(ll)re*x%Mod;
	return re;
}
int s[maxn],inv[maxn];
int p[maxn],pri,mp[maxn];
bool v[maxn];
void pre()
{
	for(int i=2;i<maxn;i++)
	{
		if(!v[i]) p[++pri]=i,mp[i]=i;
		for(int j=1,k=p[j]*i;k<maxn;j++,k=p[j]*i)
		{
			v[k]=true; mp[k]=p[j];
			if(i%p[j]==0) break;
		}
	}
	
	s[0]=1;
	for(int i=1;i<maxn;i++) s[i]=s[i-1]*(ll)i%Mod;
	inv[maxn-1]=pw(s[maxn-1],Mod-2);
	for(int i=maxn-2;i>=0;i--) inv[i]=inv[i+1]*(ll)(i+1)%Mod;
}
int C(const int i,const int j){return (ll)s[i]*inv[j]%Mod*inv[i-j]%Mod;}

int n,m;
int t[maxn],tp;

int main()
{
	pre();
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		int re=1;
		tp=0;
		while(x!=1)
		{
			int kk=mp[x]; t[++tp]=0;
			while(mp[x]==kk) t[tp]++,x/=kk;
		}
		for(int i=1;i<=tp;i++) re=(ll)re*C(y+t[i]-1,t[i])%Mod;
		re=(ll)re*pw(2,y-1)%Mod;
		printf("%d\n",re);
	}
	
    return 0;
}