#include<bits/stdc++.h>
#define re register
struct par
{
	int x,y;
}p[3010];
inline bool cmp(const par&A,const par&B){return A.x<B.x;}
int q[3010],ta,q1[3010],ta1;
int main()
{
	re int r,c,n,k;
	re long long ans=0,nw=0;
	scanf("%d%d%d%d",&r,&c,&n,&k);
	for(re int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
	std::sort(p+1,p+n+1,cmp);
	p[n+1].x=r+1;
	for(re int i=1;i<=n;i++)
	{
		ta=ta1=0;
		re int k1=k;
		for(re int j=i;j>=1;j--)
		{
			if(p[j].x)
			if(p[j].y==p[i].y)k1--;
			else if(p[j].y<p[i].y)
			{
				q[++ta]=p[j].y;
				for(re int i1=ta;q[i1]>q[i1-1];i1--)std::swap(q[i1],q[i1-1]);
			}else
			{
				q1[++ta1]=p[j].y;
				for(re int i1=ta1;q1[i1]<q1[i1-1];i1--)std::swap(q1[i1],q1[i1-1]);
			}
			if(k1<0)break;
			ta=std::min(ta,k1+1);ta1=std::min(ta1,k1+1);//printf("**************%d %d %d %d %d\n",i,j,ta,ta1,k1);
			q1[ta1+1]=c+1;q[ta+1]=0;q[0]=q1[0]=p[i].y;
			//printf("***%d %d %d %d\n",j,ta,ta1,k1);
			for(re int i1=std::min(k1,ta);i1>=0&&k1-i1<=ta1;i1--)
				nw+=(long long)(q[i1]-q[i1+1])*(q1[k1-i1+1]-q1[k1-i1])*(p[j].x-p[j-1].x);//,printf("*k*%d %d %d %d %lld\n",i1,(q[i1]-q[i1+1]),(q1[k1-i1+1]-q1[k1-i1]),(p[j].x-p[j-1].x),nw);
				//printf("***%d %d %d %d %lld\n",i,j,i1,(q[i1]-q[i1+1])*(q1[k1-i1+1]-q1[k1-i1])*(p[j].x-p[j-1].x),nw);
		}
		ans+=nw*(p[i+1].x-p[i].x);//printf("***%lld %lld %d %d\n",nw,ans,p[i].x,p[i].y);
	}
	printf("%lld\n",ans);
}