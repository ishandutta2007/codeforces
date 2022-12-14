#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int L,l,r,n,a[555555],b[555555],tree[1111111],sz,mid;
pair<int,int> k[222222];
void update(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree[node]++;
		return;
	}
	int mid=(l+r)/2;
	update(beg,en,l,mid,node*2);
	update(beg,en,mid+1,r,node*2+1);
}
int query(int x)
{
	int pos=sz+x-1,res=0;
	while(pos>=1)
	{
		res+=tree[pos];
		pos/=2;
	}
	return res;
}
bool check(int dis)
{
	int ll,rr,posl,posr;
	for (int i=1;i<=n;i++)
	{
		ll=a[i]-dis;
		rr=a[i]+dis;
		if (ll<0) 
		{
			ll+=l;
			rr+=l;
		} 
		posl=lower_bound(b+1,b+2*n+1,ll)-b;
		posr=lower_bound(b+1,b+2*n+1,rr+1)-b-1;
		posr=min(posr,posl+n-1);
		k[i-1]=make_pair(posl,posr);
	}
	sort(k,k+n);
	for (int i=0;i<n;i++)
	{
		posl=k[i].first-i;posr=k[i].second-i;
		if (posl<=0) 
		{
			posl+=n;
			posr+=n;
		}
		update(posl,posr,1,sz,1);
	}
	for (int i=1;i<=n;i++) 
	{
		if (query(i)+query(n+i)==n) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) b[i+n]=b[i]+l;
	L=0;r=l/2+1;
	sz=1;
	while(sz<n) sz*=2;
	sz*=2;
	while(L<=r)
	{
		mid=(L+r)/2;
		memset(tree,0,sizeof(tree));
		if (check(mid)) r=mid-1;
		else L=mid+1;
	}
	printf("%d\n",L);
	return 0;
}