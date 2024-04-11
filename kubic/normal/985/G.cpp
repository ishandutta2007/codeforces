#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ull unsigned long long
#define pb push_back
int n,m,dg[N],tg[N];ull c1,c2,c3,ans;vector<int> e[N],e1[N];
ull f(ull n) {return n*(n+1)/2;}
ull f1(ull x1,ull x2,ull x3)
{
	if(x1>x2) swap(x1,x2);if(x1>x3) swap(x1,x3);if(x2>x3) swap(x2,x3);
	return c1*x1+c2*x2+c3*x3;
}
int main()
{
	scanf("%d %d %llu %llu %llu",&n,&m,&c1,&c2,&c3);
	for(int i=0;i<n;++i) tg[i]=-1;
	for(int i=0;i<n;++i) ans+=c1*i*f(n-i-2)+c2*i*i*(n-i-1)+c3*i*f(i-1);
	for(int i=0,u,v;i<m;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u),++dg[u],++dg[v];
	for(int i=0;i<n;++i) for(auto j:e[i])
		if(dg[i]<dg[j] || (dg[i]==dg[j] && i<j)) e1[i].pb(j);
	for(int i=0;i<n;++i)
	{
		ull cnt1=0,cnt2=0,nw=0;sort(e[i].begin(),e[i].end());
		for(auto j:e[i]) if(i<j)
		{
			ans-=c1*f(i-1)+(c2*i+c3*j)*i;
			ans-=c2*(f(j-1)-f(i))+(c1*i+c3*j)*(j-i-1);
			ans-=c3*(f(n-1)-f(j))+(c1*i+c2*j)*(n-j-1);++cnt2;
		}else ++cnt1;ans+=c1*i*f(cnt2-1)+c2*i*cnt1*cnt2+c3*i*f(cnt1-1);
		for(auto j:e[i]) if(i>j) ++nw,ans+=c1*j*(dg[i]-nw)+c2*j*(nw-1);
			else ++nw,ans+=c2*j*(dg[i]-nw)+c3*j*(nw-1);
	}
	for(int i=0;i<n;++i)
	{
		for(auto j:e1[i]) tg[j]=i;
		for(auto j:e1[i]) for(int k:e1[j]) if(tg[k]==i) ans-=f1(i,j,k);
	}printf("%llu\n",ans);return 0;
}