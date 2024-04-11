#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
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
int n,s[N],mn,ori,ans,ax,ay,ss[N];
char a[N];
void sub2(int lim)
{
	int j=n-1;
	while(~j&&a[j]!=')')--j;
	for(int i=n,c=0;~--i;)
	{
		if(s[i+1]-2<lim)
		{
			j=i;
			while(~j&&a[j]!=')')--j;
			c=0;
		}
		else if(s[i+1]-2==lim&&i<j)++c;
		if(a[i]=='('&&ori*(lim==mn)+c>ans)ans=ori*(lim==mn)+c,ax=i,ay=j;
	}
}
void add2(int lim)
{
	int l=n,r=0,c=0;
	F(i,0,n)if(s[i]<lim)l=min(l,i),r=max(r,i);
	--l;
	while(~l&&a[l]!=')')--l;
	while(r<n&&a[r]!='(')++r;
	if(l==-1||r==n)return;
	swap(a[l],a[r]);
	F(i,0,n)ss[i+1]=ss[i]+(a[i]=='('?1:-1);
	F(i,0,n)if(ss[i]==lim)++c;
	swap(a[l],a[r]);
	if(c>ans)ans=c,ax=l,ay=r;
}
int main()
{
	read(n);
	scanf("%s",a);
	F(i,0,n)s[i+1]=s[i]+(a[i]=='('?1:-1);
	if(s[n])return puts("0\n1 1");
	F(i,0,n)mn=min(mn,s[i]);
	F(i,0,n)if(s[i]==mn)++ori;
	ans=ori;
	sub2(mn);sub2(mn-1);sub2(mn-2);
	add2(mn+1);add2(mn+2);
	printf("%d\n%d %d\n",ans,ax+1,ay+1);
	return 0;
}