#include <bits/stdc++.h>
using namespace std;
#define N 505
#define STT 1<<16
#define MOD 1000000007
int n,m,ans,b[16],st[N],ps[N],tmp[STT],dp[N][STT];
int rt,cntP;struct Point {int vl,ch[2];}pt[N];char a[N];
int f(char x)
{
	if(x>='A' && x<='D') return x-'A'+1;
	if(x>='a' && x<='d') return x-'a'+5;
	if(x=='&') return -1;if(x=='|') return -2;return 0;
}
void FWT_and(bool fl,int a[])
{
	for(int i=1;i<STT;i*=2) for(int j=0;j<STT;j+=i*2)
		for(int k=0;k<i;++k) a[j+k]=(a[j+k]+(fl?-1:1)*a[i+j+k])%MOD;
}
void FWT_or(bool fl,int a[])
{
	for(int i=1;i<STT;i*=2) for(int j=0;j<STT;j+=i*2)
		for(int k=0;k<i;++k) a[i+j+k]=(a[i+j+k]+(fl?-1:1)*a[j+k])%MOD;
}
void conv_and(int a1[],int a2[],int res[])
{
	FWT_and(0,a1);FWT_and(0,a2);
	for(int i=0;i<STT;++i) res[i]=1ll*a1[i]*a2[i]%MOD;FWT_and(1,res);
}
void conv_or(int a1[],int a2[],int res[])
{
	FWT_or(0,a1);FWT_or(0,a2);
	for(int i=0;i<STT;++i) res[i]=1ll*a1[i]*a2[i]%MOD;FWT_or(1,res);
}
void build(int &p,int l,int r)
{
	p=++cntP;if(l==r) {pt[p].vl=f(a[l]);return;}
	if(ps[r]==l) {build(p,l+1,r-1);return;}
	int t=a[r]==')'?ps[r]:r;pt[p].vl=f(a[t-1]);
	build(pt[p].ch[0],l,t-2);build(pt[p].ch[1],t,r);return;
}
void ins(int p,int vl)
{
	int stt=0;
	if(vl<5) {for(int i=0;i<16;++i) if(i>>vl-1&1) stt|=1<<i;}
	else {for(int i=0;i<16;++i) if(!(i>>vl-5&1)) stt|=1<<i;}++dp[p][stt];
}
void dfs(int p)
{
	int vl=pt[p].vl,ch[2]={pt[p].ch[0],pt[p].ch[1]};
	if(!ch[0] && !ch[1])
	{if(vl>0) ins(p,vl);else for(int i=1;i<=8;++i) ins(p,i);return;}
	dfs(ch[0]);dfs(ch[1]);
	if(vl==-1) conv_and(dp[ch[0]],dp[ch[1]],dp[p]);
	else if(vl==-2) conv_or(dp[ch[0]],dp[ch[1]],dp[p]);
	else
	{
		conv_and(dp[ch[0]],dp[ch[1]],dp[p]);
		FWT_and(1,dp[ch[0]]);FWT_and(1,dp[ch[1]]);
		conv_or(dp[ch[0]],dp[ch[1]],tmp);
		for(int i=0;i<STT;++i) dp[p][i]=(dp[p][i]+tmp[i])%MOD;
	}
}
int main()
{
	scanf("%s %d",a+1,&m);n=strlen(a+1);for(int i=0;i<16;++i) b[i]=-1;
	for(int i=1;i<=n;++i)
	{if(a[i]=='(') st[++st[0]]=i;if(a[i]==')') ps[i]=st[st[0]--];}
	build(rt,1,n);dfs(rt);
	for(int i=1,x,t;i<=m;++i)
	{
		t=0;for(int j=0;j<4;++j) {scanf("%d",&x);if(x) t|=1<<j;}
		scanf("%d",&b[t]);
	}
	for(int i=0;i<STT;++i)
	{
		bool fl=1;for(int j=0;j<16;++j) if(~b[j] && (i>>j&1)!=b[j]) fl=0;
		if(fl) ans=(ans+dp[rt][i])%MOD;
	}printf("%d\n",(ans+MOD)%MOD);return 0;
}