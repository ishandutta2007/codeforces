#include<cstdio>
#include<cstring>
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
const int N=1e6+5;
int n,ans=1;
int epc[N];
char s[N];
signed main()
{
	int lst;
	register int i;
	scanf("%s",s+1);
	n=strlen(s+1);s[n+1]='$';
	epc[0]=epc[1]=1;
	for(i=2;i<=n;i++)
		epc[i]=add(epc[i-1],epc[i-2]);
	lst=-1;
	for(i=1;i<=n;i++)
		if(s[i]=='m'||s[i]=='w')
			ans=0;
	for(i=1;i<=n+1;i++)
		if(s[i]=='u')
			lst=(lst==-1?i:lst);
		else if(lst!=-1)
			ans=mul(ans,epc[i-lst]),lst=-1;
	for(i=1;i<=n+1;i++)
		if(s[i]=='n')
			lst=(lst==-1?i:lst);
		else if(lst!=-1)
			ans=mul(ans,epc[i-lst]),lst=-1;
	printf("%d\n",ans);
	return 0;
}