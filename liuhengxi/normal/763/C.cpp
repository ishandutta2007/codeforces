#include<cstdio>
#include<set>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int m;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=m)if(b&1)(c*=a)%=m;
	return (int)c;
}
int n,a[N],nn;
set<int> s;
int getd()
{
	if(s.size()<2)return 1;
	int d=(*++s.begin()-*s.begin()+m)%m,cnt=0,k;
	for(int x:s)cnt+=(int)s.count((x+d)%m);
	k=nn-cnt;
	return (int)(d*(long long)pow(k,m-2)%m);
}
int main()
{
	read(m,n);
	F(i,0,n)read(a[i]);
	if(m==2)return printf("%d 1\n",a[0]),0;
	nn=n;
	if(2*n>m)
	{
		F(i,0,m)s.insert(i);
		F(i,0,n)s.erase(a[i]);
		nn=m-n;
	}
	else F(i,0,n)s.insert(a[i]);
	int d=getd(),x=-1;
	s.clear();
	F(i,0,n)s.insert(a[i]);
	F(i,0,n)if(!s.count((a[i]-d+m)%m))
	{
		if(~x)return puts("-1"),0;
		else x=a[i];
	}
	if(n==m)x=0;
	printf("%d %d\n",x,d);
	return 0;
}