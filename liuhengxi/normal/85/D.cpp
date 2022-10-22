#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=(1<<17)+5;
template<typename T>T &read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
struct node
{
	long long a[5];unsigned s;
	node(){a[0]=a[1]=a[2]=a[3]=a[4]=s=0;}
	node operator<<(unsigned b)const
	{node c;c.a[(0+b)%5]=a[0];c.a[(1+b)%5]=a[1];c.a[(2+b)%5]=a[2];c.a[(3+b)%5]=a[3];c.a[(4+b)%5]=a[4];return c;}
	node operator+(node b)const
	{node c=b<<s;c.a[0]+=a[0];c.a[1]+=a[1];c.a[2]+=a[2];c.a[3]+=a[3];c.a[4]+=a[4];c.s=(s+b.s)%5;return c;}
}a[N<<1];
int n,qx[N],m,v[N];
char qs[N][4];
void flip(int p,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(r-l==1)return a[p].a[0]=v[l]-a[p].a[0],a[p].s^=1,void();
	if(x<mid)flip(lc,l,mid,x);else flip(rc,mid,r,x);
	a[p]=a[lc]+a[rc];
}
int main()
{
	F(i,0,read(n))scanf("%s",qs[i]),qs[i][0]!='s'&&(v[i]=read(qx[i]),1);
	sort(v,v+n);
	m=unique(v,v+n)-v;
	F(i,0,n)
	{
		if(qs[i][0]=='s')printf("%lld\n",a[1].a[2]);
		else
		{
			int x=lower_bound(v,v+m,qx[i])-v;
			flip(1,0,m,x);
		}
	}
	return 0;
}