#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n;
LL a[MAXN],L,R,QL,QR,s[MAXN],ans;
int main()
{
	scanf("%d%I64d%I64d%I64d%I64d",&n,&L,&R,&QL,&QR);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),s[i]=s[i-1]+a[i];
	ans=1000000000000000000LL;
	for(int i=0;i<=n;i++)
	{
		int l=i,r=n-i;
		LL res=0;
		if(l>r) res+=(l-r-1)*QL;
		else if(r>l) res+=(r-l-1)*QR;
		res+=L*s[i]+R*(s[n]-s[i]);
		ans=min(ans,res);
	}
	printf("%I64d\n",ans);
	return 0;
}