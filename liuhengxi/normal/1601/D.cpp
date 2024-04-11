#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5;
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
struct person
{
	int s,a;
	friend bool operator<(person u,person v)
	{return max(u.s,u.a)!=max(v.s,v.a)?max(u.s,u.a)<max(v.s,v.a):u.s<v.s;}
}p[N];
int n,d,ans;
int main()
{
	read(n,d);
	for(int i=0;i<n;++i)
	{
		read(p[i].s,p[i].a);
		if(p[i].s<d)--i,--n;
	}
	sort(p,p+n);
	F(i,0,n)
	{
		if(p[i].s>=d)
		{
			++ans;
			d=max(d,p[i].a);
		}
	}
	printf("%d\n",ans);
	return 0;
}