#include<cstdio>
#include<cmath>
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
int T,n,q,l[N],r[N];
int a[N],b[N],s[N],f[N],m;
bool ans;
inline void pushdown(int x)
{
	if(b[x]==0)F(i,x*m,x*m+s[x])a[i]=0;
	if(b[x]==s[x])F(i,x*m,x*m+s[x])a[i]=1;
}
inline void pushup(int x)
{
	b[x]=0;
	F(i,x*m,x*m+s[x])b[x]+=a[i];
}
int main()
{
	read(T);
	while(T--)
	{
		char ch='\0';
		read(n);read(q);
		F(i,0,n)
		{
			do
			{
				ch=getchar();
			}while(ch!='0'&&ch!='1');
			f[i]=ch-'0';
		}
		F(i,0,n)
		{
			do
			{
				ch=getchar();
			}while(ch!='0'&&ch!='1');
			a[i]=ch-'0';
		}
		F(i,0,q)read(l[i]),read(r[i]),--l[i],--r[i];
		m=sqrt(n);
		if(m<1)m=1;if(m>n)m=n;
		F(i,0,(n-1)/m)s[i]=m;
		s[(n-1)/m]=(n-1)%m+1;
		F(i,0,(n-1)/m+1)b[i]=0;
		F(i,0,n)b[i/m]+=a[i];
		ans=true;
		while(~(--q))
		{
			int ll=l[q],rr=r[q],x=ll/m,y=rr/m,len=rr-ll+1;
			if(x==y)
			{
				int one=0;
				pushdown(x);
				F(i,ll,rr+1)one+=a[i];
				if(one*2==len)
				{
					ans=false;
					break;
				}
				if(one*2<len)F(i,ll,rr+1)a[i]=0;
				else F(i,ll,rr+1)a[i]=1;
				pushup(x);
			}
			else
			{
				int one=0,tmp=0;
				pushdown(x);pushdown(y);
				F(i,x+1,y)one+=b[i];
				F(i,ll,x*m+s[x])one+=a[i];
				F(i,y*m,rr+1)one+=a[i];
				if(one*2==len)
				{
					ans=false;
					break;
				}
				tmp=one*2<len?0:1;
				F(i,x+1,y)b[i]=tmp*s[i];
				F(i,ll,x*m+s[x])a[i]=tmp;
				F(i,y*m,rr+1)a[i]=tmp;
				pushup(x);pushup(y);
			}
		}
		F(i,0,(n-1)/m+1)pushdown(i);
		F(i,0,n)if(a[i]!=f[i])ans=false;
		puts(ans?"YES":"NO");
	}
	return 0;
}