#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=8005,INF=0x3fffffff;
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
int n,f[N],d[N],p[N];
char s[N],*t;
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	F(i,1,n+1)d[i]=d[i/10]+1;
	F(i,1,n+1)f[i]=INF;
	F(k,0,n)
	{
		int m=n-k;
		t=s+k;
		for(int i=1,j=0;i<m;p[++i]=j)
		{
			while(j&&t[i]!=t[j])j=p[j];
			if(t[i]==t[j])++j;
		}
		F(i,1,m+1)if(i%(i-p[i])==0)
		{
			int c=i/(i-p[i]);
			f[k+i]=min(f[k+i],f[k]+d[c]+i/c);
		}
		else f[k+i]=min(f[k+i],f[k]+1+i);
	}
	printf("%d\n",f[n]);
	return 0;
}