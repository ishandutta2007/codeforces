#include<bits/stdc++.h>
#define re register
long long x[100100],y[100100],z[100100],l1[10],r1[10],xk[10],ll[10],rr[10],xv[]={0,1,-1,1,1},yv[]={0,1,1,-1,1},zv[]={0,1,1,1,-1};
int n;
long long xxx,yy,zz;
bool check(re long long c)
{
	for(re int j=1;j<=4;j++)l1[j]=-3e18,r1[j]=3e18;
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=4;j++)
		{
			re long long vk=xv[j]*x[i]+yv[j]*y[i]+zv[j]*z[i];
			l1[j]=std::max(l1[j],vk-c);
			r1[j]=std::min(r1[j],vk+c);
		}
	}
	for(re int j=1;j<=4;j++){if(l1[j]>r1[j])return 0;}
	for(re int i=0;i<=1;i++)
	{
		re long long num=0,xx=0;
		for(re int j=1;j<=4;j++)
		{
			ll[j]=(l1[j]-i)/2,rr[j]=(r1[j]-i)/2;
			if(ll[j]*2<(l1[j]-i))ll[j]++;
			if(rr[j]*2>(r1[j]-i))rr[j]--;
			if(ll[j]>rr[j]){xx=-1;break;}
		}
		if(xx==-1)continue;
		for(re int j=2;j<=4;j++)xk[j]=ll[j],num+=xk[j];
		if(i)ll[1]--,rr[1]--;
		if(num>rr[1])continue;
		for(re int j=2;j<=4;j++)if(num<ll[1])xx=std::min(rr[j]-xk[j],rr[1]-num),xk[j]+=xx,num+=xx;
		if(num>=ll[1]&&num<=rr[1])
		{//printf("**%lld %d %lld\n",c,i,num);
			for(re int j=2;j<=4;j++)xk[j]=xk[j]*2+i;//,printf("*j*%d %lld\n",j,xk[j]);
			xxx=(xk[3]+xk[4])/2;yy=(xk[2]+xk[4])/2;zz=(xk[2]+xk[3])/2;
			for(re int j=1;j<=4;j++)
			{
				re long long vk=xv[j]*xxx+yv[j]*yy+zv[j]*zz;
				//printf("**k**%d %lld %lld %lld %lld %lld\n",j,vk,l1[j],r1[j],ll[j]*2,rr[j]*2);
			}
			//printf("****%lld %lld %lld\n",xk[3],xk[4],xx);
			return 1;
		}
	}
	return 0;
}
int main()
{
	re int t;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		for(re int i=1;i<=n;i++)scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		re long long l=0,r=3e18,mid;
		for(mid=(l+r)/2;l<r;mid=(l+r)/2)
		{
			if(check(mid))r=mid;
			else l=mid+1;
		}
		check(l);
		//re long long ll=0;
		//for(re int i=1;i<=n;i++)ll=std::max(ll,std::abs(xxx-x[i])+std::abs(yy-y[i])+std::abs(zz-z[i]));
		printf("%lld %lld %lld\n",xxx,yy,zz);
	}
}