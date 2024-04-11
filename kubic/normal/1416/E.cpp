#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define LIM 1000005
#define ll long long
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int T,n,L,R,dp[N];ll tg1;bool tg2;set<ll> z;
int rd()
{
    int res=0;char c=0;while(!isdigit(c)) c=gc();
    while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void upd(int x)
{
	set<ll>::iterator it;
	if(tg2) while(1)
	{
		it=z.upper_bound(tg1-x);
		if(it==z.begin()) break;z.erase(--it);
	}
	else while(1)
	{
		it=z.lower_bound(x-tg1);
		if(it==z.end()) break;z.erase(it);
	}tg1=x-tg1;tg2^=1;R=min(R,x-1);
	if(L>R) return;swap(L,R);L=x-L;R=x-R;
}
void slv()
{
	n=rd();R=tg1=tg2=0;L=1;z.clear();
	for(int i=1,x;i<=n;++i)
	{
		x=rd();upd(x);dp[i]=dp[i-1];
		if(x&1) {if(z.empty() && L>R) L=1,R=x-1;else ++dp[i];}
		else
		{
			ll t=x/2-tg1;if(tg2) t=-t;++dp[i];
			if(z.find(t)!=z.end() || (x/2>=L && x/2<=R))
				++dp[i],L=1,R=0,z.clear();z.insert(t);
		}
	}printf("%d\n",n*2-dp[n]);
}
int main() {T=rd();while(T--) slv();return 0;}