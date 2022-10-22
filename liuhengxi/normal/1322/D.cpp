#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=2005;
int pool[N<<4];
int n,m,l[N],w[N],c[2*N],s[2*N],*f[2*N]={pool};
int main()
{
	memset(pool,-0x3f,sizeof(pool));
	read(n,m);
	F(i,0,n)++s[--read(l[i])];
	reverse(l,l+n);
	F(i,0,n)read(w[i]);
	reverse(w,w+n);
	m+=n;
	F(i,0,m)read(c[i]);
	F(i,0,m)s[i+1]+=s[i]>>1,f[i+1]=f[i]+s[i]+1;
	F(i,0,m+1)f[i][0]=0;
	F(i,0,n)
	{
		int x=s[l[i]];
		for(int k=x;~--k;)f[l[i]][k+1]=max(f[l[i]][k+1],f[l[i]][k]+c[l[i]]-w[i]);
		F(j,l[i],m)
		{
			F(k,0,x+1)f[j+1][k>>1]=max(f[j+1][k>>1],f[j][k]+c[j+1]*(k>>1));
			x>>=1;
		}
	}
	printf("%d\n",f[m][0]);
	return 0;
}