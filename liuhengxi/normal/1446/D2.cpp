#include<cstdio>
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
constexpr int N=2e5+5;
int n,a[N],c[N],mf,mc,b,f,ans,_fir[N<<2],*fir=_fir+N;
int main()
{
	read(n);
	F(i,0,n)++c[--read(a[i])];
	F(i,0,n)mf=max(mf,c[i]);
	if(mf==n)return puts("0"),0;
	F(i,0,n)mc+=c[i]==mf;
	if(mc>=2)return printf("%d\n",n),0;
	while(b*b<n)++b;
	F(i,0,n)if(c[i]==mf)f=i;
	F(i,0,n)if(i!=f&&c[i]>=b)
	{
		int s=0;
		F(j,-n,n+1)fir[j]=-1;
		fir[0]=0;
		F(j,0,n)
		{
			if(a[j]==f)++s;
			else if(a[j]==i)--s;
			if(fir[s]==-1)fir[s]=j+1;
			else ans=max(ans,j+1-fir[s]);
		}
	}
	F(i,1,b+1)
	{
		F(j,0,n)c[j]=0;
		int d[2]={0,0},ff=0;
		auto add=[&](int j){if(a[j]==f)++ff;else--d[c[a[j]]>=i],++d[++c[a[j]]>=i];};
		auto del=[&](int j){if(a[j]==f)--ff;else--d[c[a[j]]>=i],++d[--c[a[j]]>=i];};
		for(int l=0,r=0;l<n;del(l++))
		{
			while(r<n&&ff+(a[r]==f)<=i)add(r++);
			if(d[1])ans=max(ans,r-l);
		}
	}
	printf("%d\n",ans);
	return 0;
}