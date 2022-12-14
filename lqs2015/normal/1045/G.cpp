#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,k,l[111111],r[111111],s[111111],ll[111111],rr[111111],cnt,val[111111],x,pos;
pair<pair<int,int>,int> a[111111];
pair<int,int> b[111111];
map<int,int> mp;
int rt[222222],tree[4444444],lp[4444444],rp[4444444],szz,sz;
long long ans;
void update(int x,int l,int r,int node,int del)
{
	if (l==r)
	{
		tree[node]+=del;
		return;
	}
	int mid=(l+r)/2;
	tree[node]+=del;
	if (x>mid)
	{
		if (!rp[node]) rp[node]=++szz;
		update(x,mid+1,r,rp[node],del);
	}
	else
	{
		if (!lp[node]) lp[node]=++szz;
		update(x,l,mid,lp[node],del);
	}
}
int query(int nw,int beg,int en,int l,int r)
{
	if (!nw) return 0;
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return tree[nw];
	int mid=(l+r)>>1;
	return query(lp[nw],beg,en,l,mid)+query(rp[nw],beg,en,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].first.first,&a[i].first.second,&a[i].second);
		s[i]=a[i].second;
	}
	sort(s+1,s+n+1);
	for (int i=1;i<=n;i++)
	{
		if (mp.find(s[i])==mp.end())
		{
			mp[s[i]]=++cnt;
			val[cnt]=s[i];
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		x=lower_bound(val+1,val+cnt+1,val[i]-k)-val;
		ll[i]=x;
		x=lower_bound(val+1,val+cnt+1,val[i]+k+1)-val;
		if (x>cnt || val[x]>val[i]+k) x--;
		rr[i]=x;
	}
	for (int i=1;i<=n;i++)
	{
		a[i].second=mp[a[i].second];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		x=lower_bound(a+1,a+n+1,make_pair(make_pair(a[i].first.first-a[i].first.second,0),0))-a;
		l[i]=x;
		x=lower_bound(a+1,a+n+1,make_pair(make_pair(a[i].first.first+a[i].first.second+1,0),0))-a;
		if (x>n || a[x].first.first>a[i].first.first+a[i].first.second) x--;
		r[i]=x;
	}
	for (int i=1;i<=n;i++) b[i]=make_pair(l[i],i);
	sort(b+1,b+n+1);
	sz=1;
	while(sz<n) sz*=2;
	pos=1;
	for (int i=1;i<=cnt;i++) rt[i]=++szz;
	for (int i=1;i<=n;i++)
	{
		while(pos<=n && b[pos].first<=i) 
		{
			update(b[pos].second,1,sz,rt[a[b[pos].second].second],1);
			pos++;
		}
		update(i,1,sz,rt[a[i].second],-1);
		for (int j=ll[a[i].second];j<=rr[a[i].second];j++)
		{
			ans+=(long long)query(rt[j],1,r[i],1,sz);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}