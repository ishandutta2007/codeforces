#include<bits/stdc++.h>
#define re register
long long l1[350100],r1[350100],a[350100],ta1,ta2;
#define pp std::pair<long long,long long>
#define mk(a,b) std::make_pair(a,b)
pp q1[1001000],q2[1001000];
int n;
inline bool cmp1(re pp a,re pp b){return a.first<b.first;}
inline bool cmp2(re pp a,re pp b){return a.first>b.first;}
inline long long aabs(re long long a){return a>0?a:-a;}
long long clac(re long long v)
{
	l1[1]+=v;r1[1]+=v;l1[n]+=v;r1[n]+=v;
	re long long ans=aabs(v),md=0,ll=0,rr=0;
	q1[ta1=1]=mk(0,1ll<<60);q2[ta2=1]=mk(0,1ll<<60);
	for(re int i=1;i<n;i++)
	{
		ll+=l1[i];rr+=r1[i];
		if(q2[1].first+rr>0)
		{
			q1[++ta1]=mk(-ll,2);
			std::push_heap(q1+1,q1+ta1+1,cmp1);
			re long long xx=q1[1].first+ll-rr;
			if(q1[1].second>1)q1[1].second--;
			else std::pop_heap(q1+1,q1+ta1+1,cmp1),ta1--;
			ans+=aabs(xx+rr);
			q2[++ta2]=mk(xx,1);
			std::push_heap(q2+1,q2+ta2+1,cmp2);
		}
		else
		{
			q2[++ta2]=mk(-rr,2);
			std::push_heap(q2+1,q2+ta2+1,cmp2);
			re long long xx=q2[1].first+rr-ll;//printf("-*********%lld\n",xx+ll);
			if(q2[1].second>1)q2[1].second--;
			else std::pop_heap(q2+1,q2+ta2+1,cmp2),ta2--;
			ans+=aabs(xx+ll);
			q1[++ta1]=mk(xx,1);
			std::push_heap(q1+1,q1+ta1+1,cmp1);
		}//printf("-************%d %lld %lld %lld\n",i,q1[1].first+ll,q2[1].first+rr,ans);
	}
	re long long xa=0,la;//printf("****%lld %d\n",l1[n],l1[n]>q2[1].first+rr);
	if(l1[n]>q2[1].first+rr)
	{
		la=q2[1].first;
		while(l1[n]>q2[1].first+rr)
		{
			ans+=(q2[1].first-la)*xa;
			la=q2[1].first;
			xa+=q2[1].second;
			std::pop_heap(q2+1,q2+ta2+1,cmp2);
			ta2--;
		}
		ans+=(l1[n]-la-rr)*xa;
	}
	else if(r1[n]<q1[1].first+ll)
	{
		la=q1[1].first;
		while(r1[n]<q1[1].first+ll)
		{
			ans+=(la-q1[1].first)*xa;
			la=q1[1].first;
			xa+=q1[1].second;
			//printf("***%lld %lld %lld %lld %lld %lld\n",la,xa,ans,r1[n],la+ll,r1[n]-la-ll);
			std::pop_heap(q1+1,q1+ta1+1,cmp1);
			ta1--;
		}
		ans+=(la+ll-r1[n])*xa;
	}
	l1[1]-=v;r1[1]-=v;l1[n]-=v;r1[n]-=v;
	//printf("*k*%lld\n",ans);
	return ans;
}
int main()
{
	re long long l=0,r=0,mid;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i],&l1[i],&r1[i]);
		if(i<n)r+=a[i],l1[i]=a[i]-l1[i],r1[i]=a[i]-r1[i],std::swap(l1[i],r1[i]);
		else r+=a[i],l1[i]-=a[i],r1[i]-=a[i];
	}
	l=-r;
	for(mid=l+(r-l)/2;l<r;mid=l+(r-l)/2)
	{
		if(clac(mid)<clac(mid+1))r=mid;
		else l=mid+1;
		//printf("**%lld %lld\n",l,r);
	}
	printf("%lld\n",clac(l));
	clac(-8);
}