#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=3e5+5,M=34005;
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
int T,n,a[maxn],dp[maxn];
int ch[maxn<<5][2],mx[maxn<<5][2],cnt;
signed main(){
	T=read();
	while(T--){
		memset(ch,0,sizeof(int)*2*(cnt+1));
		memset(mx,0,sizeof(int)*2*(cnt+1));
		cnt=1;
		n=read();
		for(int i=0;i<n;i++){
			a[i]=read();dp[i]=1;
			int val=a[i]^i;
			{
				int now=0;
				for(int j=31;~j;j--){
					if(ch[now][(val>>j&1)^1])dp[i]=max(dp[i],mx[ch[now][(val>>j&1)^1]][(a[i]>>j&1)^1]+1);
					if(ch[now][val>>j&1])now=ch[now][val>>j&1];
					else break;
				}
			}{
				int now=0;
				for(int j=31;~j;j--){
					if(!ch[now][val>>j&1])ch[now][val>>j&1]=++cnt;
					now=ch[now][val>>j&1];
					mx[now][i>>j&1]=max(mx[now][i>>j&1],dp[i]);
				}
			}
		}
		int mx=0;
		for(int i=0;i<n;i++)mx=max(mx,dp[i]);
		cout<<mx<<endl;
	}
}