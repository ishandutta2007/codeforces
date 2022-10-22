#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define ll long long
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int lim=1e6+1;const ll INF=1e18;char *P1,*P2,buf[LIM];
int n1,n2,m,a1[N],a2[N];ll s,ans;multiset<int> z1,z2;
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
struct BitArray
{
	ll vl[N];void upd(int x,int w) {x=max(x,0)+1;for(;x;x-=x&-x) vl[x]+=w;}
	ll qSm(int x) {x=max(x,0)+1;ll res=0;for(;x<=lim;x+=x&-x) res+=vl[x];return res;}
}BIT[2];
void ins1(int vl) {z1.insert(vl);s+=vl;}
void dlt1(int vl) {z1.erase(z1.find(vl));s-=vl;}
void ins2(int vl) {z2.insert(vl);BIT[0].upd(vl,1);BIT[1].upd(vl,vl);}
void dlt2(int vl) {z2.erase(z2.find(vl));BIT[0].upd(vl,-1);BIT[1].upd(vl,-vl);}
ll qry1(int vl,int vl1)
{
	int mn=min(*z1.begin(),*z2.begin());ll res=0;vl1-=vl;
	res=s-vl1-1ll*(n1-1)*min(mn,vl1)-BIT[1].qSm(vl1)+BIT[0].qSm(vl1)*vl1;
	return res;
}
ll qry2(int vl,int vl1)
{
	int mn=min(*z1.begin(),*z2.begin());ll res=0;vl1-=vl;
	res=s-1ll*n1*min(mn,vl1)-BIT[1].qSm(vl1)+BIT[0].qSm(vl1)*vl1;return res;
}
ll slv(int vl)
{
	int t=*--z2.end();ll res=qry1(vl,*z1.begin());
	multiset<int>::iterator it=z1.lower_bound(t+vl);
	if(it!=z1.end()) res=max(res,qry1(vl,*it));
	if(it!=z1.begin()) res=max(res,qry1(vl,*--it));
	res=max(res,max(qry2(vl,*z2.begin()),qry2(vl,t)));return res;
}
int main()
{
	n1=rd();n2=rd();m=rd();
	for(int i=1;i<=n1;++i) a1[i]=rd(),ins1(a1[i]);
	for(int i=1;i<=n2;++i) a2[i]=rd(),ins2(a2[i]);
	for(int i=1,op,x,vl;i<=m;++i)
	{
		op=rd();if(op==3) vl=rd(),printf("%lld\n",slv(vl));
		if(op==1) x=rd(),vl=rd(),dlt1(a1[x]),a1[x]=vl,ins1(a1[x]);
		if(op==2) x=rd(),vl=rd(),dlt2(a2[x]),a2[x]=vl,ins2(a2[x]);
	}return 0;
}