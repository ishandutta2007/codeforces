//??????
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define LIM 1000005
#define ll long long
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const ll INF=1e18;char *P1,*P2,buf[LIM];
int n,m,c;ll nw[N];multiset<ll> z3;
struct Edge
{
	int u,v,w;
	bool operator < (Edge t) const {return w==t.w?(u==t.u?v<t.v:u<t.u):w<t.w;}
};multiset<Edge> z1,z2,z[N];map<int,int> e[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void ins3(Edge x)
{if(z1.find(x)!=z1.end()) z2.insert(x);z1.insert(x);}
void dlt3(Edge x)
{z1.erase(z1.find(x));if(z1.find(x)!=z1.end()) z2.erase(x);}
void ins2(int u)
{
	int sz=z[u].size();ll s=0;multiset<Edge>::iterator it=z[u].begin();
	if(sz) s+=it->w,ins3(*it),++it;if(sz>1) s+=it->w,ins3(*it),++it;
	if(sz>2) s+=it->w,ins3(*it),z3.insert(nw[u]=s);
}
void dlt2(int u)
{
	int sz=z[u].size();multiset<Edge>::iterator it=z[u].begin();
	if(sz) dlt3(*it),++it;if(sz>1) dlt3(*it),++it;
	if(sz>2) dlt3(*it),z3.erase(z3.find(nw[u]));
}
void ins1(int u,Edge x) {dlt2(u);z[u].insert(x);ins2(u);}
void dlt1(int u,Edge x) {dlt2(u);z[u].erase(z[u].find(x));ins2(u);}
void ins(Edge x) {ins1(x.u,x);ins1(x.v,x);}
void dlt(Edge x) {dlt1(x.u,x);dlt1(x.v,x);}
bool chk(Edge x,Edge y)
{return x.u==y.u || x.u==y.v || x.v==y.u || x.v==y.v;}
ll qry(Edge x)
{
	multiset<Edge>::iterator it=z2.begin();
	while(it!=z2.end() && chk(*it,x)) ++it;
	return it==z2.end()?INF:x.w+it->w;
}
ll slv()
{
	int sz=z2.size();ll res=INF;if(z3.size()) res=*z3.begin();
	multiset<Edge>::iterator it=z2.begin();
	if(sz) res=min(res,qry(*it)),++it;
	if(sz>1) res=min(res,qry(*it)),++it;
	if(sz>2) res=min(res,qry(*it));return res;
}
int main()
{
	n=rd();m=rd();
	for(int i=1,u,v,w;i<=m;++i)
	{
		u=rd();v=rd();w=rd();if(u>v) swap(u,v);
		ins((Edge) {u,v,w});e[u][v]=w;
	}c=rd();printf("%lld\n",slv());
	for(int i=1,op,u,v,w;i<=c;++i)
	{
		op=rd();u=rd();v=rd();if(u>v) swap(u,v);
		if(op) w=rd(),ins((Edge) {u,v,w}),e[u][v]=w;
		else dlt((Edge) {u,v,e[u][v]}),e[u][v]=0;
		printf("%lld\n",slv());
	}return 0;
}