// Problem: CF258B Little Elephant and Elections
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF258B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-12-08 20:49:36
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define int long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=1e5+5,M=34005,mod=1e9+7;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}

int n,m,cnt[25],cnt1[25],ans;
int get(int x){int res=0;while(x){if(x%10==4||x%10==7)res++;x=x/10;}return res;}
void dfs(int x,int y,int res)
{
//	cout<<x<<" "<<y<<" "<<res<<endl;
	if(x>=7){ans+=res;ans=ans%mod;return;}
	if(res==0)return;
	for(int i=0;i<=y;i++)
		cnt[i]--,dfs(x+1,y-i,res*(cnt[i]+1)%mod),cnt[i]++;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=0;i<1e5;i++)cnt1[get(i)]++;
	for(int i=0;i<n/100000;i++)
		for(int j=0;j<=9;j++)cnt[j+get(i)]+=cnt1[j];
	for(int i=0;i<=n%100000;i++)cnt[get(i)+get(n/100000)]++;cnt[0]--;
	for(int i=1;i<=9;i++)cnt[i]--,dfs(1,i-1,cnt[i]+1),cnt[i]++;
	cout<<ans<<endl;
 	return 0;
}