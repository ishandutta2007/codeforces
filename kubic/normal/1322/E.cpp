#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define LIM 10000005
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define pb push_back
char *P1,*P2,buf[LIM];
int n,ans1,a[N],ds[N],ans[N];bool b[N];vector<int> vc[N];set<int> z,z1;
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void upd1(int l,int r,int w)
{
	int t;set<int>::iterator it=z1.lower_bound(l);
	while(it!=z1.end() && *it<=r) t=*it,ans[t]=w,++it,z1.erase(t);
}
void upd(int x,int w)
{
	int l,r;set<int>::iterator it=z.lower_bound(x);
	r=*it;l=(*--it)+1;ans1=max(ans1,(r-l)/2);
	if(b[l]) upd1(l,(l+r)/2,w);if(b[r]) upd1((l+r)/2+1,r,w);
}
void ins(int x)
{
	if(x>1 && !b[x-1]) z.erase(x-1);else z.insert(x-1);
	if(x<n && !b[x+1]) z.erase(x);else z.insert(x);b[x]=1;
}
int main()
{
	n=rd();for(int i=1;i<=n;++i) a[i]=rd(),ds[++ds[0]]=a[i];
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i) a[i]=lower_bound(ds+1,ds+ds[0]+1,a[i])-ds;
	z.insert(0);for(int i=1;i<=n;++i) z.insert(i),z1.insert(i),vc[a[i]].pb(i);
	for(int i=1;i<=ds[0];++i)
	{
		for(auto j:vc[i]) ins(j);
		for(auto j:vc[i]) {upd(j,i);if(j>1) upd(j-1,i);if(j<n) upd(j+1,i);}
	}printf("%d\n",ans1);
	for(int i=1;i<=n;++i) printf("%d ",ds[ans[i]]);return 0;
}