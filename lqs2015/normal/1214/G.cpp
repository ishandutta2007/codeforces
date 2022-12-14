#include<bits/stdc++.h>
using namespace std;
int n,m,q,num[2222],x,l,r;
bitset<2222> b[2222],cur,xr[2222];
set<pair<int,int> > s;
set<int> ok;
set<pair<int,int> >::iterator it,iter,itt;
bool can(int x,int y)
{
	assert(b[x].count()<=b[y].count());
	return ((b[y]&b[x]).count()!=b[x].count());
}
void era(int x)
{
	it=s.lower_bound(make_pair(num[x],x));
	if (it==s.begin())
	{
		if (ok.find(x)!=ok.end()) ok.erase(ok.find(x));
	}
	else
	{
		iter=it;iter++;itt=it;itt--;
		if (iter==s.end()) 
		{
			if (ok.find(itt->second)!=ok.end()) ok.erase(ok.find(itt->second));
		}
		else 
		{
			if (ok.find(itt->second)!=ok.end()) ok.erase(ok.find(itt->second));
			if (ok.find(x)!=ok.end()) ok.erase(ok.find(x));
			if (can(itt->second,iter->second)) ok.insert(itt->second);
		}
	}
	s.erase(it);
}
void add(int x)
{
	s.insert(make_pair(num[x],x));
	it=s.lower_bound(make_pair(num[x],x));
	if (it==s.begin())
	{
		iter=it;iter++;
		if (iter!=s.end() && can(x,iter->second)) ok.insert(x);
	}
	else
	{
		iter=it;iter++;itt=it;itt--;
		if (iter==s.end()) 
		{
			if (can(itt->second,x)) ok.insert(itt->second);
		}
		else 
		{
			if (ok.find(itt->second)!=ok.end()) ok.erase(ok.find(itt->second));
			if (can(itt->second,x)) ok.insert(itt->second);
			if (can(x,iter->second)) ok.insert(x);
		}
	}
}
void findit(int x)
{
	it=s.lower_bound(make_pair(num[x],x));
	it++;
	int y=it->second,xx,yy;
	cur=b[x]&(~b[y]);
	xx=cur._Find_first();
	cur=b[y]&(~b[x]);
	yy=cur._Find_first();
	if (x>y) swap(x,y);
	if (xx>yy) swap(xx,yy);
	printf("%d %d %d %d\n",x,xx,y,yy); 
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	cur.reset();xr[0]=cur;
	for (int i=1;i<=m;i++) 
	{
		cur.set(i);
		xr[i]=cur;
	}
	for (int i=1;i<=n;i++) b[i].reset();
	for (int i=1;i<=n;i++) s.insert(make_pair(0,i));
	while(q--)
	{
		scanf("%d%d%d",&x,&l,&r);
		era(x);
		b[x]^=xr[r];b[x]^=xr[l-1];
		num[x]=b[x].count();
		add(x);
		if (ok.empty()) printf("-1\n");
		else findit(*ok.begin());
	}
	return 0;
}