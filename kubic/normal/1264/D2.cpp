#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define MOD 998244353
int n,cnt,cnt1,ans,fc[N],invF[N],s[N],s1[N];char a[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
int C(int x,int y) {return 1ll*fc[x]*invF[y]%MOD*invF[x-y]%MOD;}
int main()
{
	scanf("%s",a+1);n=strlen(a+1);fc[0]=invF[0]=1;
	for(int i=1;i<=n;++i) fc[i]=1ll*fc[i-1]*i%MOD;
	invF[n]=qPow(fc[n],MOD-2);
	for(int i=n-1;i;--i) invF[i]=1ll*invF[i+1]*(i+1)%MOD;
	for(int i=1;i<=n;++i)
	{if(a[i]=='?') ++cnt;if(a[i]==')') ++cnt1;}
	for(int i=cnt;i>=0;--i) s[i]=add(s[i+1],C(cnt,i));
	for(int i=cnt-1;i>=0;--i) s1[i]=add(s1[i+1],C(cnt-1,i));
	for(int i=1;i<=n;++i)
	{
		if(a[i]=='?') W(ans,s1[max(i-cnt1,0)]);
		if(a[i]=='(') W(ans,s[max(i-cnt1,0)]);
	}printf("%d\n",ans);return 0;
}