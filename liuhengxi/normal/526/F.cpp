#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,INF=0x3fffffff;
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
int n,p[N],t[N<<1],*s=t+N,mx[N];
long long ans;
void solve(int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return void(++ans);
	solve(l,mid);solve(mid,r);
	mx[mid]=-INF;
	for(int i=mid,j=mid,k=mid+1,mn=INF,mx2=-INF;--i>=l;)
	{
		mn=min(mn,p[i]);mx2=max(mx2,p[i]+1);
		while(j<r&&p[j]>mn)mx[j+1]=max(mx[j],p[j]+1),++j,++s[mx[j]-j];
		while(k<=j&&mx[k]<mx2)--s[mx[k]-k],++k;
		ans+=s[mn-i];
		if(i+mx2-mn<=j&&i+mx2-mn>mid&&mx[i+mx2-mn]<mx2)++ans;
	}
	for(int i=mid,j=mid,mn=INF;--i>=l;)
	{
		mn=min(mn,p[i]);
		while(j<r&&p[j]>mn)++j,s[mx[j]-j]=0;
	}
	for(int i=mid,j=mid,k=mid-1,mn=INF,mx2=-INF;i<r;++i)
	{
		mn=min(mn,p[i]);mx2=max(mx2,p[i]+1);
		while(j>l&&p[j-1]>mn)--j,mx[j]=max(mx[j+1],p[j]+1),++t[mx[j]+j];
		while(k>=j&&mx[k]<mx2)--t[mx[k]+k],--k;
		ans+=t[mn+i+1];
		if(i+1-mx2+mn>=j&&i+1-mx2+mn<mid&&mx[i+1-mx2+mn]<mx2)++ans;
	}
	for(int i=mid,j=mid,mn=INF;i<r;++i)
	{
		mn=min(mn,p[i]);
		while(j>l&&p[j-1]>mn)--j,t[mx[j]+j]=0;
	}
}
int main()
{
	read(n);
	F(i,0,n)
	{
		int r,c;read(r,c);
		p[--r]=--c;
	}
	solve(0,n);
	printf("%lld\n",ans);
	return 0;
}