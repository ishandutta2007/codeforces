#include<cstdio>
#include<algorithm>
#include<set>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct element{int a,b;}a[N],b[N];
bool cmpa(element u,element v){return u.a<v.a;}
bool cmpb(element u,element v){return u.b<v.b;}
int n,delta;
long long ans;
set<int,greater<int>> s;
int main()
{
	read(n);
	F(i,0,n)read(a[i].a);
	F(i,0,n)read(a[i].b);
	F(i,0,n)ans+=abs(a[i].a-a[i].b);
	F(i,0,n)b[i]=a[i];
	sort(a,a+n,cmpa);sort(b,b+n,cmpb);
	s.insert(0);
	for(int i=0,j=0,mx=0;i<n;++i)
	{
		while(j<n&&a[j].a<=b[i].b)s.insert(a[j].b),mx=max(mx,a[j++].b);
		if(b[i].a>b[i].b&&mx>=b[i].a)delta=max(delta,b[i].a-b[i].b);
		delta=max(delta,*s.lower_bound(b[i].a)-b[i].b);
	}
	s.clear();s.insert(0);
	for(int i=0,j=0,mx=0;i<n;++i)
	{
		while(j<n&&b[j].b<=a[i].a)s.insert(b[j].a),mx=max(mx,b[j++].a);
		if(a[i].b>a[i].a&&mx>=a[i].b)delta=max(delta,a[i].b-a[i].a);
		delta=max(delta,*s.lower_bound(a[i].b)-a[i].a);
	}
	printf("%lld\n",ans-(delta<<1));
	return 0;
}