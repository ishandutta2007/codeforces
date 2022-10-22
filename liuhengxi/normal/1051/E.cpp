#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
char a[N],l[N],r[N],la[N<<1],ra[N<<1];
int n,ls,rs,las,ras,laz[N<<1],raz[N<<1],f[N],g[N];
void add(int &x,const int &y){x+=((x+=y-MOD)>>31)&MOD;}
void sub(int &x,const int &y){x+=((x-=y)>>31)&MOD;}
void zfunc(char *s,int *z,int n)
{
	for(int i=1,d=0;i<=n;++i)
	{
		if(i<d+z[d])z[i]=d+z[d]-i<z[i-d]?d+z[d]-i:z[i-d];
		while(s[z[i]]==s[i+z[i]])++z[i];
		if(i+z[i]>d+z[d])d=i;
	}
}
int cmpl(int x,int y)
{
	int same=laz[ls+1+x];
	if(y-x!=ls)return y-x-ls;
	if(ls==same)return 0;
	return a[x+same]-l[same];
}
int cmpr(int x,int y)
{
	int same=raz[rs+1+x];
	if(y-x!=rs)return y-x-rs;
	if(rs==same)return 0;
	return a[x+same]-r[same];
}
int main()
{
	scanf("%s%s%s",a,l,r);
	while(a[n])++n;
	while(l[ls])++ls;
	while(r[rs])++rs;
	F(i,0,ls)la[i]=l[i];
	la[ls]='#';
	F(i,0,n)la[i+ls+1]=a[i];
	las=ls+n+1;
	F(i,0,rs)ra[i]=r[i];
	ra[rs]='#';
	F(i,0,n)ra[i+rs+1]=a[i];
	ras=rs+n+1;
	zfunc(la,laz,las);
	zfunc(ra,raz,ras);
	f[0]=1;
	for(int i=0,j=0,k=0;i<n;++i,add(f[i],g[i]),add(g[i+1],g[i]))
	{
		if(a[i]=='0')
		{
			if(l[0]=='0')add(f[i+1],f[i]);
		}
		else
		{
			if(j<=i)j=i+1;
			while(j<=n&&cmpl(i,j)<0)++j;
			if(k<=i)k=i+1;
			while(k<=n&&cmpr(i,k)<=0)++k;
			add(g[j],f[i]);sub(g[k],f[i]);
		}
	}
	printf("%d\n",f[n]);
	return 0;
}