#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct ques
{
	int l,x,id;
	bool operator<(ques b)const{return l<b.l;}
}qq[N];
int n,q,a[N],p[20],ans[N],use;
void insert(int x)
{
	for(int i=19;~i;--i)
	{
		if((x>>i&1)==0)continue;
		if(!p[i])p[i]=x,++use;
		x^=p[i];
	}
}
int pow(int a,int n)
{
	int c=1;
	while(n)
	{
		if(n&1)c=(long long)c*a%MOD;
		n>>=1;a=(long long)a*a%MOD;
	}
	return c;
}
int query(int l,int x)
{
	for(int i=19;~i;--i)if(x>>i&1)x^=p[i];
	return x?0:pow(2,l-use);
}
int main()
{
	int j=0;
	read(n);read(q);
	F(i,0,n)read(a[i]);
	F(i,0,q)read(qq[qq[i].id=i].l),read(qq[i].x);
	sort(qq,qq+q);
	F(i,0,q)
	{
		while(j<qq[i].l)insert(a[j++]);
		ans[qq[i].id]=query(qq[i].l,qq[i].x);
	}
	F(i,0,q)printf("%d\n",ans[i]);
	return 0;
}