#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
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
//const int N=4e6+5;
//int rev[N];
//inline void ntt(int *f,int n,int p)
//{
//	int w,wi,u,t;
//	register int i,j,k;
//	for(i=0;i<n;i++)
//		if(i<(rev[i]=i&1?rev[i^1]|n>>1:rev[i>>1]>>1))
//			swap(f[i],f[rev[i]]);
//	for(i=1;wi=qpow(p^1?inv3:3,(mod-1)/(i<<1)),i<<1<=n;i<<=1)
//		for(j=0;w=1,j<n;j+=i<<1)
//			for(k=0;k<i;w=mul(w,wi),k++)
//				u=f[j+k],t=mul(w,f[j+k+i]),f[j+k]=add(u,t),f[j+k+i]=sub(u,t);
//	if(!~p)
//		for(w=qpow(n,mod-2),i=0;i<n;i++)
//			f[i]=mul(w,f[i]);
//	return;
//}
const int N=1005,M=5e5+5;
int n,m,sum;
int a[N],b[N];
bitset<M> epc[N];
bool ba[N],bb[N];
inline void solve()
{
	register int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),ba[i]=0;
//	random_shuffle(a+1,a+n+1);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]),bb[i]=0;
//	random_shuffle(b+1,b+m+1);
	if(n!=m)
		return puts("No"),void();
	for(sum=0,i=1;i<=n;i++)
		sum+=a[i];
	if(sum&1)
		return puts("No"),void();
	epc[0].reset();epc[0][0]=1;
	for(i=1;i<=n;i++)
		epc[i]=epc[i-1]|epc[i-1]<<a[i];
	if(!epc[n][sum>>1])
		return puts("No"),void();
	for(k=sum>>1;k;)
	{
		for(i=1;i<=n;i++)
			if(epc[i][k])
			{
				ba[i]=1;k-=a[i];
				break;
			}
	}
	for(sum=0,i=1;i<=n;i++)
		sum+=b[i];
	if(sum&1)
		return puts("No"),void();
	epc[0].reset();epc[0][0]=1;
	for(i=1;i<=n;i++)
		epc[i]=epc[i-1]|epc[i-1]<<b[i];
	if(!epc[n][sum>>1])
		return puts("No"),void();
	for(k=sum>>1;k;)
	{
		for(i=1;i<=n;i++)
			if(epc[i][k])
			{
				bb[i]=1;k-=b[i];
				break;
			}
	}
	for(i=1;i<=n;i++)
		if(ba[i])
			a[i]*=-1;
	for(i=1;i<=m;i++)
		if(bb[i])
			b[i]*=-1;
	int _=0;
	sort(a+1,a+n+1,greater<int>());
//	for(i=1;i<=n;i++)
//		if(a[i]>0)
//			_=i;
//	reverse(a+1,a+_+1);
	sort(b+1,b+n+1,greater<int>());
	for(i=1;i<=n;i++)
		if(b[i]<0)
		{
			reverse(a+1,a+i);
			reverse(b+i,b+n+1);
			break;
		}
	puts("Yes");
	int x=0,y=0;
	printf("%d %d\n",x,y);
	for(i=1;i<=n;i++)
	{
		y+=b[i];printf("%d %d\n",x,y);
		x+=a[i];
		if(i!=n)
			printf("%d %d\n",x,y);
	}
	return;
}
signed main()
{
//	srand(233);
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}