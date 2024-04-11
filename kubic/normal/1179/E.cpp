#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define ll long long
#define pb push_back
const ll lim=1e18;mt19937 rand1(998244353);
int n;ll m,ansL[N],ansR[N];vector<int> z;
int rdm(int l,int r) {return rand1()%(r-l+1)+l;}
ll qry(int x,ll y)
{ll res;printf("? %d %lld\n",x,y);fflush(stdout);scanf("%lld",&res);return res;}
ll find(int x,ll l,ll r,ll vl)
{while(l<=r) {ll mid=(l+r)/2;if(qry(x,mid)<vl) l=mid+1;else r=mid-1;}return l;}
ll slv1(int x,ll l,ll r,ll vl,vector<int> z,vector<int> &res1,vector<int> &res2)
{
	int p=z[rdm(0,z.size()-1)];ll t=find(p,l,r,vl),t1;vector<int> z1,z2,z3;
	z1.clear();z2.clear();z3.clear();z3.pb(p);
	for(auto i:z) if(i!=p)
	{t1=qry(i,t);if(t1>vl) z1.pb(i);else if(t1<vl) z2.pb(i);else z3.pb(i);}
	if(x<=z1.size())
	{
		for(auto i:z2) res2.pb(i);for(auto i:z3) res2.pb(i);
		return slv1(x,l,t-1,vl,z1,res1,res2);
	}
	if(x<=z1.size()+z3.size())
	{
		for(auto i:z1) res1.pb(i);for(auto i:z2) res2.pb(i);
		for(int i=0;i<z3.size();++i) (i<x-z1.size()?res1:res2).pb(z3[i]);return t;
	}for(auto i:z1) res1.pb(i);for(auto i:z3) res1.pb(i);
	return slv1(x-z1.size()-z3.size(),t+1,r,vl,z2,res1,res2);
}
void slv(int l1,int r1,ll l,ll r,vector<int> z)
{
	if(z.size()<2) {ansL[z[0]]=l;ansR[z[0]]=r;return;}
	int mid=(l1+r1)/2;ll t;vector<int> z1,z2;z1.clear();z2.clear();
	t=slv1(mid-l1,l,r,m*mid,z,z1,z2);slv(l1,mid,l,t,z1);slv(mid,r1,t,r,z2);
}
int main()
{
	scanf("%d %lld",&n,&m);m/=n;for(int i=1;i<=n;++i) z.pb(i);slv(0,n,0,lim,z);
	puts("!");for(int i=1;i<=n;++i) printf("%lld %lld\n",ansL[i],ansR[i]);
	fflush(stdout);return 0; 
}