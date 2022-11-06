#include<bits/stdc++.h>
#define re register
long long c[500100];
unsigned long long q1[500100],q2[500100];
int pp[500100];
unsigned long long rad(){return rand()*32767llu*32767llu*32767llu+rand()*32767llu*32767llu+rand()*32767llu+rand();}
inline bool cmp(re int a,re int b){return q2[a]<q2[b];}
long long gcd(re long long a,re long long b){return b?gcd(b,a%b):a;}
int main()
{
	srand(time(0));
	re int t,x,y,n,m;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d",&n,&m);
		for(re int i=1;i<=n;i++)scanf("%lld",&c[i]),q1[i]=rad(),q2[i]=0,pp[i]=i;
		for(re int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			q2[y]^=q1[x];
		}
		std::sort(pp+1,pp+n+1,cmp);
		re long long ans=0,nw=0;
		for(re int i=1;i<=n;i++)
		if(q2[pp[i]]!=0){
			if(i==1||q2[pp[i]]!=q2[pp[i-1]])
			{
				ans=gcd(nw,ans);nw=0;
			}
			nw+=c[pp[i]];
		}
		ans=gcd(nw,ans);
		printf("%lld\n",ans);
	}
}