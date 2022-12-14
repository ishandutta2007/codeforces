#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;
const long long mod=1e9+9;
map<pair<long long,long long>,long long> mp;
long long m,x,y,pos,ans,p;
pair<long long,long long> a[111111];
set<long long> s;
long long finddown(long long x,long long y,pair<long long,long long> &p)
{
	long long res=0;
	if (mp[make_pair(x+1,y-1)]) 
	{
		res++;
		p=make_pair(x+1,y-1);
	}
	if (mp[make_pair(x,y-1)])
	{
		res++;
		p=make_pair(x,y-1);
	}
	if (mp[make_pair(x-1,y-1)])
	{
		res++;
		p=make_pair(x-1,y-1);
	}
	return res;
}
bool check(long long x,long long y)
{
	pair<long long,long long> p;
	if (mp[make_pair(x,y+1)] && finddown(x,y+1,p)==1) return 0;
	if (mp[make_pair(x+1,y+1)] && finddown(x+1,y+1,p)==1) return 0; 
	if (mp[make_pair(x-1,y+1)] && finddown(x-1,y+1,p)==1) return 0; 
	return 1;
}
void update(long long x,long long y)
{
	mp[make_pair(x,y)]=0;
	if (mp[make_pair(x-1,y-1)] && check(x-1,y-1)) s.insert(mp[make_pair(x-1,y-1)]-1);
	if (mp[make_pair(x,y-1)] && check(x,y-1)) s.insert(mp[make_pair(x,y-1)]-1);
	if (mp[make_pair(x+1,y-1)] && check(x+1,y-1)) s.insert(mp[make_pair(x+1,y-1)]-1);
	pair<long long,long long> p;
	if (mp[make_pair(x-1,y+1)] && finddown(x-1,y+1,p)==1 && s.find(mp[p]-1)!=s.end()) s.erase(s.find(mp[p]-1));
	if (mp[make_pair(x,y+1)] && finddown(x,y+1,p)==1 && s.find(mp[p]-1)!=s.end()) s.erase(s.find(mp[p]-1));
	if (mp[make_pair(x+1,y+1)] && finddown(x+1,y+1,p)==1 && s.find(mp[p]-1)!=s.end()) s.erase(s.find(mp[p]-1));
}
long long mul(long long a,long long n)
{
	long long res=1ll,p=a;
	for (long long i=n;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
void print()
{
	for (set<long long>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"fuck"<<endl;
}
int main()
{
	scanf("%I64d",&m);
	for (long long i=0;i<m;i++) 
	{
		scanf("%I64d%I64d",&x,&y);
		a[i]=make_pair(x,y);
		mp[make_pair(x,y)]=i+1;
	}
	for (long long i=0;i<m;i++)
	{
		if (check(a[i].first,a[i].second)) s.insert(i);
	}
	while(pos<m)
	{
		p=*s.rbegin();
		s.erase(s.find(p));
		ans=(ans+p*mul(m,m-pos-1)%mod)%mod;
		update(a[p].first,a[p].second);
		pos++;
		if (pos>=m) break;
		p=*s.begin();
		s.erase(s.find(p));
		ans=(ans+p*mul(m,m-pos-1)%mod)%mod;
		update(a[p].first,a[p].second);
		pos++;
	}
	printf("%I64d\n",ans);
	return 0;
}