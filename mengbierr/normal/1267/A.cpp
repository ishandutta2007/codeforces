#include<bits/stdc++.h>
#define inf 2e18
typedef long long int ll;
using namespace std;
ll a[500005],b[500005],t[500005];
int n;
map<ll,vector<int> >mp;
set<pair<ll,int> >st;
typedef set<pair<ll,int> >::iterator pt;
ll p[500005];int tot=0;
ll mn[500005];
ll val[2000005];
struct segtree
{
	int ls;
	int rs;
	ll minn;
}tree[2000005];
int cntt=1;
void build(int z,int l,int r)
{
	int mid=l+r>>1;
	if(l==r)
	{
		tree[z].minn=val[mid];
		return;
	}
	tree[z].ls=++cntt;
	tree[z].rs=++cntt;
	build(tree[z].ls,l,mid);
	build(tree[z].rs,mid+1,r);
	tree[z].minn=min(tree[tree[z].ls].minn,tree[tree[z].rs].minn);
}
ll query(int z,int l,int r,int x,int y)
{
	int mid=l+r>>1;
	if(l==x&&r==y) return tree[z].minn;
	if(y<=mid) return query(tree[z].ls,l,mid,x,y);
	else if(x>mid) return query(tree[z].rs,mid+1,r,x,y);
	else return min(query(tree[z].ls,l,mid,x,mid),query(tree[z].rs,mid+1,r,mid+1,y));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i],&b[i],&t[i]);
		mp[a[i]].push_back(i);
		mp[b[i]-t[i]+1].push_back(i);
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		/*pair<ll,int>tmp=*it;
		if(p[tot]!=tmp.first)p[++tot]=tmp.first;
		if(st.empty())mn[tot-1]=inf;
		else mn[tot-1]=(*st.begin()).first;
		pair<ll,int>tmp2=make_pair(t[tmp.second],tmp.second);
		if(st.count(tmp2))st.erase(tmp2);
		else st.insert(tmp2);*/
		p[++tot]=(*it).first;
		for(int j=0;j<(*it).second.size();j++)
		{
			int v=(*it).second[j];
			pair<ll,int>tmp2=make_pair(t[v],v);
			if(st.count(tmp2))st.erase(tmp2);
			else st.insert(tmp2);
		}
		if(st.empty())mn[tot]=inf;
		else mn[tot]=(*st.begin()).first;
	}
	
	for(int i=1;i<=tot;i++)val[i]=p[i]+mn[i];
	build(1,1,500000);
	
	ll ans=0,now=p[1];
	p[++tot]=2e18;mn[tot]=2e18;
	//for(int i=1;i<=tot;i++)cerr<<p[i]<<" ";cerr<<endl;
	//for(int i=1;i<=tot;i++)cerr<<mn[i]<<" ";cerr<<endl;
	while(now<p[tot-1])
	{
		//cerr<<"now="<<now<<endl;
		int duan=upper_bound(p+1,p+tot+1,now)-p-1;//cerr<<"duan="<<duan<<endl;
		ll cnt=(p[duan+1]-now-1)/mn[duan];
		ans+=cnt;
		now+=cnt*mn[duan];
		ans++;
		now+=mn[duan];
		int duan2=upper_bound(p+1,p+tot+1,now)-p-1;//cerr<<"duan2="<<duan2<<endl;
		
		if(duan+1<=min(tot-2,duan2))
		now=min(now,query(1,1,500000,duan+1,min(tot-2,duan2)));
	}
	printf("%lld\n",ans);
	return 0;
}
/*
2
5 7 1
1 9 2

3
1 10 4
6 12 3
9 13 2

3
1 13 4
6 11 2
9 13 3

*/