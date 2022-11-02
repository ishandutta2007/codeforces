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
const int maxn=1e5+5,M=34005;
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
int n,m,k,l,r,B,c[maxn],L[maxn],R[maxn],cnt=0,len[maxn],Q,ans[maxn],s[maxn];
int sum[maxn],ch[maxn][27],fail[maxn],tot=0,b[maxn];
string a[maxn];vector<int>e[maxn];
void ins(int x){
	int now=0;len[x]=a[x].length();
	for(int i=0;i<len[x];i++){//cout<<i<<" "<<now<<endl;
		if(!ch[now][a[x][i]-'a'])ch[now][a[x][i]-'a']=++tot;
		now=ch[now][a[x][i]-'a'];
	}b[x]=now;
}
void getfail(){
	queue<int>q;
	for(int i=0;i<26;i++)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<26;i++){
			int v=ch[x][i];
			if(v)fail[v]=ch[fail[x]][i],q.push(v);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	for(int i=1;i<=tot;i++)e[fail[i]].pb(i);
}
void dfs(int x){L[x]=++cnt;for(auto i:e[x])dfs(i);R[x]=cnt;}
void add(int x,int num){for(int i=x;i<=cnt+1;i+=lowbit(i))c[i]+=num;}
int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=c[i];return res;}
struct que{int id,l,r,k;}q[maxn];
bool cmp(int a,int b){return q[a].k<q[b].k;}
vector<int>g;vector<pi>h[maxn];
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();Q=read();
	for(int i=1;i<=n;i++){
		cin>>a[i];//cout<<"A";
		ins(i);m+=len[i];
	}
	getfail();dfs(0);
	B=(int)m/sqrt(Q*log(m)/log(2));
	//B=0;
	for(int i=1;i<=Q;i++){
		l=read(),r=read(),k=read();q[i].l=l,q[i].r=r,q[i].id=i,q[i].k=k;
		if(len[k]>B){g.pb(i);}
		else h[l-1].pb(mp(i,-1)),h[r].pb(mp(i,1));
	}
	sort(g.begin(),g.end(),cmp);int z=g.size();
	for(int i=0;i<z;i++){
		int p=g[i];
		if(i==0||q[p].k!=q[g[i-1]].k){
			int u=q[p].k;memset(sum,0,sizeof sum);
			for(int j=0,now=0;j<len[u];j++)now=ch[now][a[u][j]-'a'],sum[L[now]]++;
			for(int j=1;j<=cnt;j++)sum[j]=sum[j]+sum[j-1];
			for(int j=1;j<=n;j++)s[j]=s[j-1]+sum[R[b[j]]]-sum[L[b[j]]-1];
		}ans[p]=s[q[p].r]-s[q[p].l-1];
	}//exit(0);
	for(int i=1;i<=n;i++){
		add(L[b[i]],1),add(R[b[i]]+1,-1);
		//cout<<L[b[i]]<<" "<<R[b[i]]<<endl;
		for(auto y:h[i]){
			int p=y.fi,u=q[p].k;
			for(int j=0,now=0;j<len[u];j++)now=ch[now][a[u][j]-'a'],ans[p]+=y.se*query(L[now]);
		}
	}
	for(int i=1;i<=Q;i++)printf("%lld\n",ans[i]);
 	return 0;
}