#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],inv[N],ans;
int main()
{
	read(n);
	inv[1]=1;
	F(i,2,n+1)inv[i]=(MOD-MOD/i)*(long long)inv[MOD%i]%MOD;
	F(i,0,n)read(a[i]);
	sort(a,a+n);
	for(int l=0,r=0;;l=r)
	{
		while(r<n&&a[r]==a[l])++r;
		if(r==n)break;
		(ans+=(r-l)*(long long)a[l]%MOD*inv[n-l]%MOD)%=MOD;
	}
	F(i,1,n+1)ans=(long long)ans*i%MOD;
	printf("%d\n",ans);
	return 0;
}