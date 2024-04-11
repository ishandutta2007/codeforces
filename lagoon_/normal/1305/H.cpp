#include<bits/stdc++.h>
#define re register
int n,m,p[100100],p1[100100],ll[100100],rr[100100],l[100100],r[100100],bg[100100],nx[100100],ta;
std::pair<int,int>pp[200100];
long long t;
int check2(re int m,re int x,re int v,re int tp)
{
	ta=0;
	for(re int i=1;i<=n;i++)
	{
		p1[i]=p[i]-p[i-1]+((i==1)<<30);
		if(p1[i]>0)bg[i]=ta,nx[ta]=i,ta=i;
	}
	nx[ta]=n+1;nx[n+1]=n+2;bg[n+1]=ta;p1[n+1]=1<<30;
	for(re int i=1,l=n+1,r=n+1;i<=x;i++)
	{
		re int xx=n-v+1;
		while(l>xx)l=bg[l];
		while(nx[l]<=xx)l=nx[l];
		while(bg[r]>=xx)r=bg[r];
		while(r<xx)r=nx[r];
		if(l==xx)
		{
			p1[l]--;
			if(!p1[l])nx[bg[l]]=nx[l],bg[nx[l]]=bg[l],r=l=nx[l];
		}
		else
		{
			p1[l]--;p1[r]--;p1[l+r-xx]++;nx[l]=bg[r]=l+r-xx;
			bg[l+r-xx]=l;nx[l+r-xx]=r;
			if(!p1[l])nx[bg[l]]=nx[l],bg[nx[l]]=bg[l],l=nx[l];
			if(!p1[r])nx[bg[r]]=nx[r],bg[nx[r]]=bg[r],r=nx[r];
		}
	}
	p1[1]-=1<<30;
	for(re int i=2;i<=n;i++)p1[i]+=p1[i-1];//,printf("**a**%d %d %d %d %d %d\n",x,v,tp,i,m,p1[i]);
	for(re int i=1;i<=n;i++)if(p1[i]<0)return 0;else if(p1[i]>m)return -1;
	std::sort(p1+1,p1+n+1);
	ta=0;
	for(re int i=1;i<=m;i++)
	{
		if(tp)ll[i]=std::min(v,r[i])-std::min(v,r[i-1])+((i==1)<<30);
		else ll[i]=l[i]-l[i-1]+((i==1)<<30);//printf("*k*k*%d %d\n",i,ll[i]);
		if(ll[i]>0)bg[i]=ta,nx[ta]=i,ta=i;
	}
	nx[ta]=m+1;nx[m+1]=m+2;bg[m+1]=ta;ll[m+1]=1<<30;
	for(re int i=1,l=m+1,r=m+1;i<=n;i++)
	{
		re int xx=m-p1[i]+1;
		while(l>xx)l=bg[l];
		while(nx[l]<=xx)l=nx[l];
		while(bg[r]>=xx)r=bg[r];
		while(r<xx)r=nx[r];
//		printf("*******************%d %d\n",l,r);
		if(l==xx)
		{
			ll[l]--;
			if(!ll[l])nx[bg[l]]=nx[l],bg[nx[l]]=bg[l],r=l=nx[l];
		}
		else
		{
			ll[l]--;ll[r]--;ll[l+r-xx]++;nx[l]=bg[r]=l+r-xx;
			bg[l+r-xx]=l;nx[l+r-xx]=r;
			if(!ll[l])nx[bg[l]]=nx[l],bg[nx[l]]=bg[l],l=nx[l];
			if(!ll[r])nx[bg[r]]=nx[r],bg[nx[r]]=bg[r],r=nx[r];
		}
	}
	ll[1]-=1<<30;
	for(re int i=2;i<=m;i++)ll[i]+=ll[i-1];//,printf("*****%d %d %d %d %d\n",x,v,tp,i,ll[i]);
	for(re int i=1;i<=m;i++)if(tp?ll[i]<0:(ll[i]>0))return 0;
	return 1;
}
int lk;
bool check1(re int x)
{
	re int l1=l[m],r1=r[m-x+1];
	if(l1>r1)return 0;
	for(re int mid=(l1+r1+1)/2;l1<r1;mid=(l1+r1+1)/2)
	{
		if(check2(m-x,x,mid,0))l1=mid;
		else r1=mid-1;
	}
	lk=l1;
//	printf("*******%d %d %d %d\n",x,l1,l[m],r[m-x+1]);
	return (check2(m-x,x,l1,0)==1)&&(check2(m-x,x,l1,1)==1);
}
void initp()
{
	re long long t1=t;
	re int nw=0;
	for(re int i=1;i<=n;i++)
	{
		t-=p[i],t1-=rr[i];
		pp[2*i-1]=std::make_pair(p[i],i);
		pp[2*i]=std::make_pair(rr[i],i);
	}
	if(t<0||t1>0){puts("-1 -1");exit(0);}
	std::sort(pp+1,pp+2*n+1);
	for(re int i=1;i<=2*n;i++)
	{
		re int x=pp[i].first,y=pp[i].second,x1=pp[i+1].first;
		if(p[y]==-1)p[y]=x,nw--;
		else p[y]=-1,nw++;
		if(1ll*(x1-x)*nw>=t)
		{
			re int xx=t/nw;t%=nw;
			for(re int i=1;i<=n;i++)if(p[i]==-1){if(t)t--,p[i]=x+xx+1;else p[i]=x+xx;}
			break;
		}else t-=1ll*(x1-x)*nw;
	}
	std::sort(p+1,p+n+1);
}
int main()
{
	re int x,y,l1,r1,q;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i],&rr[i]);
	}
	for(re int i=1;i<=m;i++)r[i]=n;
	scanf("%d",&q);
	for(;q--;)
	{
		scanf("%d%d",&x,&y);
		l[x]=r[x]=y;
	}
	scanf("%lld",&t);
	initp();
	for(re int i=2;i<=m;i++)r[i]=std::min(r[i],r[i-1]);//,printf("**rr**%d %d\n",i,r[i]);
	for(re int i=m;i;i--)l[i]=std::max(l[i],l[i+1]);
	std::reverse(l+1,l+m+1);
	std::reverse(r+1,r+m+1);
	if(!check1(1)){puts("-1 -1");return 0;}
	l1=1;r1=m;
	for(re int mid=(l1+r1+1)/2;l1<r1;mid=(l1+r1+1)/2)
	{
		if(check1(mid))l1=mid;
		else r1=mid-1;
	}
	check1(l1);
	printf("%d %d\n",l1,lk);
}