#include<iostream>
#include<cstdlib>
#include<cstdio>
#define re register
#define double float
const double eps=1e-5;
double p1[100100],p2[100100],p3[100100];
int main()
{
	re int n,a,b,a1,b1;re double num;
	scanf("%d%d%d",&n,&a,&b);for(re int i=1;i<=n;i++)scanf("%f",&p1[i]);
	for(re int i=1;i<=n;i++)scanf("%f",&p2[i]),p3[i]=p1[i]+p2[i]-p1[i]*p2[i];
	for(re double l=0,r=1,mid=(l+r)/2;;mid=(l+r)/2)
	{
		for(re double l1=0,r1=1,mid1=(l1+r1)/2;;mid1=(l1+r1)/2)
		{
			a1=b1=num=0;
			for(re int i=1;i<=n;i++)
			{
				if(p1[i]-mid>p2[i]-mid1)
				{
					if(p1[i]>=p3[i]-mid1){if(p1[i]-mid>0)a1++,num+=p1[i]-mid;}
					else if(p3[i]-mid-mid1>0)a1++,b1++,num+=p3[i]-mid-mid1;
				}else
				{
					if(p2[i]>=p3[i]-mid){if(p2[i]-mid1>0)b1++,num+=p2[i]-mid1;}
					else if(p3[i]-mid-mid1>0)a1++,b1++,num+=p3[i]-mid-mid1;
				}
			}
			if(b1==b||l1+eps>=r1){num+=b*mid1;break;}
			if(b1<b)r1=mid1-eps;
			else l1=mid1+eps;
		}
		if(a1==a||l+eps>=r){num+=a*mid;break;}
		if(a1<a)r=mid-eps;
		else l=mid+eps;
	}printf("%.3f",num);
}