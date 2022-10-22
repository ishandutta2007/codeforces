#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct participant{int l,r;}p[N];
int n,m,k,c[N],d[N],s[N],t[N],ans;
int main()
{
	read(n);read(m);read(k);n<<=1;
	F(i,0,m)
	{
		read(p[i].l);read(p[i].r);
		(--p[i].l)<<=1;p[i].r<<=1;
	}
	F(mid,k,n-k+1)
	{
		F(i,0,n+1)c[i]=d[i]=0;
		F(i,0,m)
		{
			if(p[i].l+p[i].r<mid<<1)// left
				++c[p[i].l],--c[p[i].r];
			else// right
				++d[p[i].l],--d[p[i].r];
		}
		F(i,0,n)c[i+1]+=c[i];
		F(i,0,n)d[i+1]+=d[i];
		F(i,0,n)s[i+1]=s[i]+c[i];
		F(i,0,n)t[i+1]=t[i]+d[i];
		F(offset,0,n)
		{
			int l1=mid-k-offset,r1=l1+(k<<1);
			int l2=mid-k+offset,r2=l2+(k<<1);
			if(l1<0||r2>n)break;
			ans=max(ans,s[r1]-s[l1]+t[r2]-t[l2]);
		}
	}
	printf("%d\n",ans>>1);
	return 0;
}