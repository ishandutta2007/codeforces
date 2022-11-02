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
#define lowbit (x&-x)
#define int long long
const int maxn=6e3+5,M=34005,mod=1e9+7;
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
int n,f[maxn],a[maxn],ans;
struct Sam
{
	int ch[maxn][2],fa[maxn],len[maxn],tot=1,las=1;
	void ins(int x){
		int p=las,t=++tot;las=t;len[t]=len[p]+1;
		for(;!ch[p][x];p=fa[p])ch[p][x]=t;
		if(!p){fa[t]=1;return;}int q=ch[p][x];
		if(len[q]==len[p]+1){fa[t]=q;return;}
		fa[++tot]=fa[q];len[tot]=len[p]+1;fa[q]=fa[t]=tot;
		ch[tot][0]=ch[q][0],ch[tot][1]=ch[q][1];
		for(;ch[p][x]==q;p=fa[p])ch[p][x]=tot;
	}
	void work()
	{
		for(int i=1;i<=n;i++){
			a[i]=read();ins(a[i]);f[i+1]=1;
			for(int j=i;j>=1;j--){
				f[j]=f[j+1]+f[j+2]+f[j+3]+f[j+4];
				if(!a[j]&&!a[j+1]&&a[j+2]&&a[j+3])f[j]-=f[j+4];
				if(!a[j]&&a[j+1]&&!a[j+2]&&a[j+3])f[j]-=f[j+4];
				if(a[j]&&a[j+1]&&a[j+2]&&!a[j+3])f[j]-=f[j+4];
				if(a[j]&&a[j+1]&&a[j+2]&&a[j+3])f[j]-=f[j+4];
				f[j]%=mod;ans+=f[j];
				//cout<<f[j]<<" ";
			}
			for(int j=len[fa[las]];j>=1;j--)
				ans-=f[i-j+1];
			ans=ans%mod;
			cout<<ans<<endl;
		}
	}
}sam;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();sam.work();
	
 	return 0;
}