#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=5e5+5,M=34005;
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
int n,m,T,a[maxn],ans,b[maxn],f[maxn];map<int,int>g;
void solve(){
	n=read();ans=n;g.clear();
	for(int i=1;i<=n;i++)a[i]=read(),f[i]=1e9,b[i]=b[i-1]^a[i];f[0]=0;g[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)f[i]=f[i-1];
		else f[i]=f[i-1]+1;
		if(i>1&&a[i]==a[i-1])f[i]=min(f[i],f[i-2]+1);
		if(g.count(b[i]))f[i]=min(f[i],g[b[i]]+i);
		g[b[i-1]]=min(g[b[i-1]],f[i-1]-i);
	}printf("%d\n",f[n]);
} 
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)solve();
 	return 0;
}