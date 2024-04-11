#include<bits/stdc++.h>
using namespace std;
struct com
{
	long long x,y;
	int ind;
};
com a[500000];
bool comp(com g,com h) {
	return (g.y-g.x)<(h.y-h.x);
}
bool comi(com g,com h) {
	return g.ind<h.ind;
}
long long n,m;
long long sol[500000];
int main()
{
	scanf("%lld %lld",&n,&m);
	long long x,y,s=0;
	for(int i=0;i<n;i++) {
		scanf("%lld %lld",&x,&y);
		a[i].x=x;
		a[i].y=y;
		a[i].ind=i;
		s+=x;
	}
	for(int i=0;i<n;i++) {
		sol[i]+=s;
		sol[i]+=(a[i].x)*(n-2);
	}
	//for(int i=0;i<n;i++) printf("%lld ",sol[i]);
	sort(a,a+n,comp);
	s=0;
	for(int i=0;i<n;i++) {
		//cout<<a[i].ind<<" "<<a[i].y-a[i].x<<endl;
		sol[a[i].ind]+=s;
		sol[a[i].ind]+=(n-i-1)*(a[i].y-a[i].x);
		s+=a[i].y-a[i].x;
	}
	int u,v;
	sort(a,a+n,comi);
	for(int i=0;i<m;i++) {
		scanf("%d %d",&u,&v);
		u--;
		v--;
		s=min(a[u].x+a[v].y,a[u].y+a[v].x);
		sol[u]-=s;
		sol[v]-=s;
	}
	for(int i=0;i<n;i++) printf("%lld ",sol[i]);
	return 0;
}