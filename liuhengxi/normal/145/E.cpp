#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,len0[N<<2],len1[N<<2],len01[N<<2],len10[N<<2],tag[N<<2];
char s[N];
inline void flip(int p)
{swap(len0[p],len1[p]);swap(len01[p],len10[p]);tag[p]^=1;}
inline void pushdown(int p)
{
	if(tag[p])flip(lc),flip(rc);
	tag[p]=0;
}
inline void pushup(int p)
{
	len0[p]=len0[lc]+len0[rc];
	len1[p]=len1[lc]+len1[rc];
	len01[p]=max(len01[lc]+len1[rc],len0[lc]+len01[rc]);
	len10[p]=max(len10[lc]+len0[rc],len1[lc]+len10[rc]);
}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)
	{
		(s[l]=='4'?len0[p]:len1[p])=1;
		len01[p]=len10[p]=1;
		return;
	}
	build(lc,l,mid);build(rc,mid,r);
	pushup(p);
}
void update(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return flip(p);
	pushdown(p);
	update(lc,l,mid,x,y);update(rc,mid,r,x,y);
	pushup(p);
}
int main()
{
	read(n);read(m);
	scanf("%s",s);
	build(1,0,n);
	while(m--)
	{
		scanf("%s",s);
		if(s[0]=='c')printf("%d\n",len01[1]);
		else
		{
			int l,r;read(l);read(r);--l;
			update(1,0,n,l,r);
		}
	}
	return 0;
}