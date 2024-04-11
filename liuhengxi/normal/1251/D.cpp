#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct employee
{
	int l,r;
	bool operator<(employee b)const{return l<b.l;}
}a[N];
int t,n;
long long s;
bool check(int v)
{
	int cnt=0;
	long long c=0;
	F(i,0,n)if(a[i].r<v)++cnt,c+=a[i].l;
	if(cnt>n/2)return false;
	cnt=n-cnt-n/2-1;
	F(i,0,n)if(a[i].r>=v)
	{
		if(cnt>0)
		{
			c+=a[i].l;
			--cnt;
		}
		else c+=v>a[i].l?v:a[i].l;
	}
	return c<=s;
}
int solve()
{
	int l=a[0].l,r=0;
	F(i,0,n)if(a[i].r>r)r=a[i].r;
	++r;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(s);
		F(i,0,n)read(a[i].l),read(a[i].r);
		sort(a,a+n);
		printf("%d\n",solve());
	}
	return 0;
}