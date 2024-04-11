#include<bits/stdc++.h>
#define re register
long long a[10],b[10],q1a[1010],q1b[1010],q2a[1010],q2b[1010];
int p[10],p1[10],ta1,ta2,qqa[1010],qqb[1010],tta;
inline bool cmp(re int a1,re int a2){return a[a1]<a[a2];}
inline bool cmp1(re int a1,re int a2){return b[a1]<b[a2];}
inline long long aabs(re long long a){return a>0?a:-a;}
long long gcd(re long long a,re long long b)
{
	if(!b)return a;
	return gcd(b,a%b); 
}
int main()
{
	scanf("%lld%lld%lld%lld",&a[1],&a[2],&a[3],&a[4]);
	scanf("%lld%lld%lld%lld",&b[1],&b[2],&b[3],&b[4]);
	for(re int i=1;i<=4;i++)p[i]=p1[i]=i;
	std::sort(p+1,p+5,cmp);
	std::sort(p1+1,p1+5,cmp1);
	re long long g=0,g1=0;
	for(re int i=1;i<=3;i++)g=gcd(g,a[p[i+1]]-a[p[i]]);
	for(re int i=1;i<=3;i++)g1=gcd(g1,b[p1[i+1]]-b[p1[i]]);
	if(g!=g1){puts("-1");return 0;}
	if(g==0){if(a[1]==b[1])puts("0");else puts("-1");return 0;}
	re long long kk=(g-a[1]%g)%g,qw=0;
	if((g-b[1]%g)%g!=kk){puts("-1");return 0;}
	for(re int i=1;i<=4;i++)a[i]=(a[i]+kk)/g,b[i]=(b[i]+kk)/g,qw+=(a[i]%2==0)-(b[i]%2==0);
	if(qw!=0){puts("-1");return 0;}
	std::sort(p+1,p+5,cmp);
	while(a[p[4]]-a[p[1]]>1)
	{
		re long long dis=a[p[4]]-a[p[1]];
		if((a[p[2]]-a[p[1]])*4ll>=dis&&(a[p[2]]-a[p[1]])*4ll<=3ll*dis)
		{
			ta1++;q1a[ta1]=a[p[1]];q1b[ta1]=a[p[2]];a[p[1]]=2*a[p[2]]-a[p[1]];
		}
		else if((a[p[4]]-a[p[3]])*4ll>=dis&&(a[p[4]]-a[p[3]])*4ll<=3ll*dis)
		{
			ta1++;q1a[ta1]=a[p[4]];q1b[ta1]=a[p[3]];a[p[4]]=2*a[p[3]]-a[p[4]];
		}
		else
		{
			if(std::min((a[p[4]]-a[p[2]]),(a[p[2]]-a[p[1]]))>=std::min((a[p[4]]-a[p[3]]),(a[p[3]]-a[p[1]])))
			{
				if(a[p[2]]-a[p[1]]<=a[p[4]]-a[p[2]])
				{
					ta1++;q1a[ta1]=a[p[3]];q1b[ta1]=a[p[2]];
					a[p[3]]=2*a[p[2]]-a[p[3]];
					ta1++;q1a[ta1]=a[p[3]];q1b[ta1]=a[p[1]];
					a[p[3]]=2*a[p[1]]-a[p[3]];
				}
				else
				{
					ta1++;q1a[ta1]=a[p[3]];q1b[ta1]=a[p[4]];
					a[p[3]]=2*a[p[4]]-a[p[3]];
					ta1++;q1a[ta1]=a[p[3]];q1b[ta1]=a[p[2]];
					a[p[3]]=2*a[p[2]]-a[p[3]];
				}
			}
			else
			{
				if(a[p[4]]-a[p[3]]<=a[p[3]]-a[p[1]])
				{
					ta1++;q1a[ta1]=a[p[2]];q1b[ta1]=a[p[3]];
					a[p[2]]=2*a[p[3]]-a[p[2]];
					ta1++;q1a[ta1]=a[p[2]];q1b[ta1]=a[p[4]];
					a[p[2]]=2*a[p[4]]-a[p[2]];
				}
				else
				{
					ta1++;q1a[ta1]=a[p[2]];q1b[ta1]=a[p[1]];
					a[p[2]]=2*a[p[1]]-a[p[2]];
					ta1++;q1a[ta1]=a[p[2]];q1b[ta1]=a[p[3]];
					a[p[2]]=2*a[p[3]]-a[p[2]];
				}
			}
		}
		std::sort(p+1,p+5,cmp);
		//printf("****%lld %d %lld %lld %lld %lld %lld %lld %lld %lld\n",a[p[4]]-a[p[1]],ta1,a[p[1]],a[p[2]],a[p[3]],a[p[4]],q1a[1],q1b[1],q1a[2],q1b[2]);
	}
	std::sort(p1+1,p1+5,cmp1);
	while(b[p1[4]]-b[p1[1]]>1)
	{
		re long long dis=b[p1[4]]-b[p1[1]];
		if((b[p1[2]]-b[p1[1]])*4ll>=dis&&(b[p1[2]]-b[p1[1]])*4ll<=3ll*dis)
		{b[p1[1]]=2*b[p1[2]]-b[p1[1]];
			ta2++;q2a[ta2]=b[p1[1]];q2b[ta2]=b[p1[2]];
		}
		else if((b[p1[4]]-b[p1[3]])*4ll>=dis&&(b[p1[4]]-b[p1[3]])*4ll<=3ll*dis)
		{b[p1[4]]=2*b[p1[3]]-b[p1[4]];
			ta2++;q2a[ta2]=b[p1[4]];q2b[ta2]=b[p1[3]];
		}
		else
		{
			if(std::min((b[p1[4]]-b[p1[2]]),(b[p1[2]]-b[p1[1]]))>=std::min((b[p1[4]]-b[p1[3]]),(b[p1[3]]-b[p1[1]])))
			{
				if(b[p1[2]]-b[p1[1]]<=b[p1[4]]-b[p1[2]])
				{
					b[p1[3]]=2*b[p1[2]]-b[p1[3]];
					ta2++;q2a[ta2]=b[p1[3]];q2b[ta2]=b[p1[2]];
					b[p1[3]]=2*b[p1[1]]-b[p1[3]];
					ta2++;q2a[ta2]=b[p1[3]];q2b[ta2]=b[p1[1]];
				}
				else
				{
					b[p1[3]]=2*b[p1[4]]-b[p1[3]];
					ta2++;q2a[ta2]=b[p1[3]];q2b[ta2]=b[p1[4]];
					b[p1[3]]=2*b[p1[2]]-b[p1[3]];
					ta2++;q2a[ta2]=b[p1[3]];q2b[ta2]=b[p1[2]];
				}
			}
			else
			{
				if(b[p1[4]]-b[p1[3]]<=b[p1[3]]-b[p1[1]])
				{
					b[p1[2]]=2*b[p1[3]]-b[p1[2]];
					ta2++;q2a[ta2]=b[p1[2]];q2b[ta2]=b[p1[3]];
					b[p1[2]]=2*b[p1[4]]-b[p1[2]];
					ta2++;q2a[ta2]=b[p1[2]];q2b[ta2]=b[p1[4]];
				}
				else
				{
					b[p1[2]]=2*b[p1[1]]-b[p1[2]];
					ta2++;q2a[ta2]=b[p1[2]];q2b[ta2]=b[p1[1]];
					b[p1[2]]=2*b[p1[3]]-b[p1[2]];
					ta2++;q2a[ta2]=b[p1[2]];q2b[ta2]=b[p1[3]];
				}
			}
		}
		std::sort(p1+1,p1+5,cmp1);
	}
	re long long mx=-1ll<<60,mx1=-1ll<<60;
	for(re int i=1;i<=4;i++)mx=std::max(mx,a[i]),mx1=std::max(mx1,b[i]);
	if((mx-mx1)%2!=0)
	{
		for(re int i=1;i<=4;i++)if(a[i]==mx)g=i;
		for(re int i=1;i<=4;i++)if(a[i]!=mx)
		{
			ta1++;q1a[ta1]=a[i];q1b[ta1]=a[g];a[i]+=2;
		}
		mx++;
	}
	//printf("***%lld %lld %lld %lld %lld %lld\n",a[1],a[2],a[3],a[4],mx,mx1);
	mx=(mx1-mx);
	std::sort(p+1,p+5,cmp);
	while(2*(a[p[4]]-a[p[1]])<=aabs(mx))
	{
		if((a[p[3]]-a[p[1]])>=(a[p[4]]-a[p[2]]))
		{
			ta1++;q1a[ta1]=a[p[3]];q1b[ta1]=a[p[1]];
			tta++;qqa[tta]=p[3];qqb[tta]=p[1];
			a[p[3]]=2*a[p[1]]-a[p[3]];
		}
		else
		{
			ta1++;q1a[ta1]=a[p[2]];q1b[ta1]=a[p[4]];
			tta++;qqa[tta]=p[2];qqb[tta]=p[4];
			a[p[2]]=2*a[p[4]]-a[p[2]];
		}
		std::sort(p+1,p+5,cmp);//printf("***%lld %lld %lld %lld %lld %lld\n",a[1],a[2],a[3],a[4],2*(a[p[4]]-a[p[1]]),aabs(mx));
	}//printf("*****%d\n",tta);
	for(re int i=tta;i;i--)
	{
		ta1++;q1a[ta1]=a[qqa[i]];q1b[ta1]=a[qqb[i]];
		a[qqa[i]]=2*a[qqb[i]]-a[qqa[i]];
		std::sort(p+1,p+5,cmp);
		re long long dd=a[p[4]]-a[p[1]];
		if(aabs(mx)>=2*dd)
		{
			if(mx>0)
			{
				for(re int ii=1;ii<=3;ii++)
				ta1++,q1a[ta1]=a[p[ii]],q1b[ta1]=a[p[4]],a[p[ii]]=2*a[p[4]]-a[p[ii]];
				for(re int ii=2;ii<=4;ii++)
				ta1++,q1a[ta1]=a[p[ii]],q1b[ta1]=a[p[1]],a[p[ii]]=2*a[p[1]]-a[p[ii]];
				mx-=2*dd;
			}else
			{
				for(re int ii=2;ii<=4;ii++)
				ta1++,q1a[ta1]=a[p[ii]],q1b[ta1]=a[p[1]],a[p[ii]]=2*a[p[1]]-a[p[ii]];
				for(re int ii=1;ii<=3;ii++)
				ta1++,q1a[ta1]=a[p[ii]],q1b[ta1]=a[p[4]],a[p[ii]]=2*a[p[4]]-a[p[ii]];
				mx+=2*dd;
			}
		}
		std::sort(p+1,p+5,cmp);
	}
	re int qwq=ta1+ta2;
	for(re int i=1;i<=ta1;i++)if(q1a[i]==q1b[i])qwq--;
	for(re int i=1;i<=ta2;i++)if(q2a[i]==q2b[i])qwq--;
	printf("%d\n",qwq);
	for(re int i=1;i<=ta1;i++)if(q1a[i]!=q1b[i])printf("%lld %lld\n",q1a[i]*g1-kk,q1b[i]*g1-kk);
	for(re int i=ta2;i;i--)if(q2a[i]!=q2b[i])printf("%lld %lld\n",q2a[i]*g1-kk,q2b[i]*g1-kk);
}