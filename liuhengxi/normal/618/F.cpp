#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N],b[N],l[N],p[N];
long long s[N],t[N];
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)read(b[i]);
	F(i,0,n)s[i+1]=s[i]+a[i];
	F(i,0,n)t[i+1]=t[i]+b[i];
	F(i,0,n)l[i]=-1;
	if(s[n]>=t[n])
	{
		for(int i=0,j=0;i<=n;++i)
		{
			while(j<n&&t[j+1]<=s[i])++j;
			p[i]=j;
			if(~l[s[i]-t[j]])
			{
				int k=l[s[i]-t[j]];
				printf("%d\n",i-k);
				F(I,k,i)printf("%d ",I+1);
				puts("");
				printf("%d\n",j-p[k]);
				F(I,p[k],j)printf("%d ",I+1);
				puts("");
				return 0;
			}
			l[s[i]-t[j]]=i;
		}
	}
	else
	{
		for(int i=0,j=0;i<=n;++i)
		{
			while(j<n&&s[j+1]<=t[i])++j;
			p[i]=j;
			if(~l[t[i]-s[j]])
			{
				int k=l[t[i]-s[j]];
				printf("%d\n",j-p[k]);
				F(I,p[k],j)printf("%d ",I+1);
				puts("");
				printf("%d\n",i-k);
				F(I,k,i)printf("%d ",I+1);
				puts("");
				return 0;
			}
			l[t[i]-s[j]]=i;
		}
	}
	return 0;
}