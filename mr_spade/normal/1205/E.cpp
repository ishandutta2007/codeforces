#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::__gcd;
using std::vector;
const int mod=1e9+7;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
const int N=1e5+5;
int n,k0,ans;
vector<int> f[N];
signed main()
{
	register int i,j,k;
	scanf("%d%d",&n,&k0);
	for(i=1;i<=n-1;i++)
	{
		f[i].resize(2*((n-1)/i)+1);
		f[i][0]=f[i][1]=0;
		for(j=2;j<=1+(n-1)/i;j++)
			f[i][j]=j-1;
		for(j=2+(n-1)/i;j<=2*((n-1)/i);j++)
			f[i][j]=(n-1)/i*2-j+1;
	}
	for(i=n-1;i>=1;i--)
		for(j=2;i*j<=n-1;j++)
			for(k=2;k<=2*((n-1)/(i*j));k++)
				f[i][k*j]=sub(f[i][k*j],f[i*j][k]);
	for(i=1;i<=n-1;i++)
		for(j=2;j<=2*((n-1)/i);j++)
			if(j*i>=n+i)
				ans=add(ans,mul(f[i][j],qpow(k0,j*i-n)));
			else
				ans=add(ans,mul(f[i][j],qpow(k0,i)));
	printf("%d\n",mul(ans,qpow(qpow(k0,n),mod-2)));
	return 0;
}