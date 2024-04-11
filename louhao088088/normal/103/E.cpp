// LUOGU_RID: 90802043
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
const int maxn=705,M=2e5+5,mod=998244353,inf=1e10;
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
int n,m,x,cnt=1,sum=0,a[maxn],s,t,mx=0,dis[maxn];
int head[maxn],cur[maxn],to[M],nex[M],w[M];
void Add(int x,int y,int z){to[++cnt]=y;w[cnt]=z;nex[cnt]=head[x];head[x]=cnt;}
void add(int x,int y,int z){Add(x,y,z),Add(y,x,0);}
bool bfs(){
	queue<int>q;memset(dis,-1,sizeof dis);
	memcpy(cur,head,sizeof head);
	q.push(s);dis[s]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=nex[i])
			if(dis[to[i]]==-1&&w[i])
				dis[to[i]]=dis[x]+1,q.push(to[i]);
	}return dis[t]!=-1;
}
int dfs(int x,int flow){
	if(x==t)return flow;
	int sum=0;
	for(int i=cur[x];i&&flow;i=nex[i]){
		int v=to[i];cur[x]=i;
		if(dis[v]==dis[x]+1&&w[i]){
			int k=dfs(v,min(flow,w[i]));
			w[i]-=k,w[i^1]+=k;sum+=k,flow-=k;
		}
	}return sum;
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();s=2*n+1,t=2*n+2;
	for(int i=1;i<=n;i++){
		m=read();
		for(int j=1;j<=m;j++)x=read(),add(i+n,x,inf);
	}
	for(int i=1;i<=n;i++){
		a[i]=read();sum+=a[i];
		add(s,i+n,inf-a[i]),add(i,t,inf);
	}
	while(bfs())mx+=dfs(s,inf*10);
	//cout<<mx<<endl;
	cout<<sum+mx-inf*n<<endl;
 	return 0;
}