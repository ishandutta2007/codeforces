#include <bits/stdc++.h>
using namespace std;
#define N 35005
#define ll long long
int n,a[N],L[N],R[N];ll s,L1,R1,tgL,tgR,ans=1e18;
priority_queue<ll> qL;
priority_queue<ll,vector<ll>,greater<ll>> qR;
ll min(ll x,ll y) {return x<y?x:y;}
ll max(ll x,ll y) {return x>y?x:y;}
ll slv(ll x)
{
	ll res=abs(x),tL,tR,t;
	tgL=tgR=0;L[1]+=x;R[1]+=x;L[n]-=x;R[n]-=x;
	while(!qL.empty()) qL.pop();qL.push(0);
	while(!qR.empty()) qR.pop();qR.push(0);
	for(int i=1;i<=n;++i)
	{
		tgL+=L[i];tgR+=R[i];tL=qL.top()+tgL;tR=qR.top()+tgR;
		if(tL>0)
		{
			qL.push(max(-tgL,0));qL.push(max(-tgL,0));
			res+=tL;qR.push(qL.top()+tgL-tgR);qL.pop();
		}
		else if(tR<0)
		{
			qR.push(min(-tgR,0));qR.push(min(-tgR,0));
			res-=tR;qL.push(qR.top()+tgR-tgL);qR.pop();
		}else qL.push(-tgL),qR.push(-tgR);
	}tL=qL.top()+tgL;tR=qR.top()+tgR;
	if(tL>0) for(int i=0;;++i)
	{
		t=qL.top()+tgL;if(t<=0) {res+=tL*i;break;}
		res+=(tL-t)*i;tL=t;qL.pop();
	}
	else if(tR<0) for(int i=0;;++i)
	{
		t=qR.top()+tgR;if(t>=0) {res-=tR*i;break;}
		res+=(t-tR)*i;tR=t;qR.pop();
	}L[1]-=x;R[1]-=x;L[n]+=x;R[n]+=x;return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
		scanf("%d %d %d",&x,&L[i],&R[i]),L[i]-=x,R[i]-=x,s+=x;
	L1=-s;R1=s;
	while(R1-L1>6)
	{
		ll mid=(L1+R1)/2;
		if(slv(mid)<slv(mid+1)) R1=mid;else L1=mid+1;
	}for(ll i=L1;i<=R1;++i) ans=min(ans,slv(i));
	printf("%lld\n",ans);return 0;
}