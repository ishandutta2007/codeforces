#include<cstdio>
#include<ctime>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
const long long LLINF=0x3ffffffffffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct count
{
	int c[N];long long ans;
	long long add(int x){return ans+=c[x]++;}
	long long del(int x){return ans-=--c[x];}
}c;
int n,k,a[N];
long long f[N],g[N],t[N];
void dp(int l,int r,int kl,int kr)
{
	int mid=(l+r)>>1,kkr=kr<mid?kr:mid,k=kkr-1;
	if(l==r)return;
	//[kr,mid)
	for(int i=k;i>=kl;--i)
	{
		t[i]=c.add(a[i])+f[i];
		if(t[k]>t[i])k=i;
	}
	F(i,kl,kkr)c.del(a[i]);
	g[mid]=t[k];
	//[kr,mid)
	F(i,mid>kr?mid:kr,(mid+r+1)>>1)c.add(a[i]);
	//[kr,(mid+r+1)>>1)
	dp(mid+1,r,k,kr);
	//[kr,(mid+r+1)>>1)
	F(i,mid>kr?mid:kr,(mid+r+1)>>1)c.del(a[i]);
	//[kr,mid)
	F(i,k+1,kr<mid?kr:mid)c.add(a[i]);
	//[k+1,mid)
	F(i,k+1>(l+mid)>>1?k+1:(l+mid)>>1,mid)c.del(a[i]);
	//[k+1,(l+mid)>>1)
	dp(l,mid,kl,k+1);
	//[k+1,(l+mid)>>1)
	F(i,k+1>(l+mid)>>1?k+1:(l+mid)>>1,mid)c.add(a[i]);
	//[k+1,mid)
	F(i,k+1,kr<mid?kr:mid)c.del(a[i]);
	//[kr,mid)
}
int main()
{
	read(n);read(k);
	if(n==1)return puts("0"),0;
	F(i,0,n)read(a[i]);
	F(i,1,n+1)f[i]=LLINF;
	while(k--)
	{
		dp(1,n+1,0,n);
		F(i,1,n+1)f[i]=g[i];
	}
	printf("%lld\n",f[n]);
	return 0;
}