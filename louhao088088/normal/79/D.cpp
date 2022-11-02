// LUOGU_RID: 91833718
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
const int maxn=2e4+25,M=2e5+5,mod=998244353,inf=1e9;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],b[maxn],k,ans[maxn],d[maxn];
int f[maxn*60],pos[maxn],dis[105][maxn],g[25],x;
void bfs(int s,int op){
	queue<int>q;q.push(s);dis[op][s]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=1;i<=m;i++){
			int y=x+d[i];
			if(y>0&&dis[op][y]>=inf&&y<=n)dis[op][y]=dis[op][x]+1,q.push(y);
		}
		for(int i=1;i<=m;i++){
			int y=x-d[i];
			if(y>0&&dis[op][y]>=inf&&y<=n)dis[op][y]=dis[op][x]+1,q.push(y);
		}
	}
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	n=read(),k=read(),m=read();
	for(int i=1;i<=k;i++)x=read(),a[x]=1;
	for(int i=1;i<=n+1;i++)b[i]=a[i]^a[i-1];
	n++;int cnt=0;
	for(int i=1;i<=n;i++)
		if(b[i]==1)pos[cnt++]=i;
	for(int i=1;i<=m;i++)d[i]=read();
	for(int i=0;i<cnt;i++)bfs(pos[i],i);
	
	int S=(1<<cnt);//cout<<S<<endl;
	memset(f,0x3f,sizeof f);f[0]=0;
	for(int i=0;i<S;i++)if(f[i]<inf){
		int tot=0;
		for(int j=0;j<cnt;j++)if(!(i>>j&1))g[++tot]=j;
		for(int j=1;j<tot;j++)
			for(int k=j+1;k<=tot;k++){
				int o=i|(1<<g[j])|(1<<g[k]);
				f[o]=min(f[o],f[i]+dis[g[k]][pos[g[j]]]);
			}
	}if(f[S-1]>=inf)puts("-1");
	else cout<<f[S-1];
 	return 0;
}