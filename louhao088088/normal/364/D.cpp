#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=1e6+5,M=2e6+5;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,a[maxn],ans=0,k,f[maxn],d[maxn],cnt;
mt19937 rnd(random_device{}());
map<int,bool>vis;
void solve(int x){
	if(vis[x]) return ;
	vis[x]=1,cnt=0;
	for(int i=1;i*i<=x;i++)if(x%i==0){
		d[++cnt]=i;
		if(i*i!=x) d[++cnt]=x/i;
	}
	sort(d+1,d+cnt+1),fill(f+1,f+cnt+1,0);
	for(int i=1;i<=n;i++) f[lower_bound(d+1,d+1+cnt,__gcd(a[i],x))-d]++;
	for(int i=cnt;i>=1;i--){
		int tot=0;
		for(int j=i;j<=cnt;j++) if(d[j]%d[i]==0) tot+=f[j];
		if(tot>=(n+1)/2){ans=max(ans,d[i]);break;}
	}
} 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();k=12;
	for(int i=1;i<=n;i++)a[i]=read();
	while(clock()<=1.0*3.6*CLOCKS_PER_SEC)solve(a[rnd()%n+1]);
	cout<<ans<<endl;
 	return 0;
}