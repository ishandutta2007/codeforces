#include<cstdio>
const int mod=1e9+7;
inline int add(int a,int b)
{
	return (a+=b)>mod?a-mod:a;
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
int n,m;
signed main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",qpow(sub(qpow(2,m),1),n));
	return 0;
}