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
struct que{int id,l,r,k;}q[maxn];vector<pi>h[maxn];
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();Q=read();
	for(int i=1;i<=n;i++)
		cin>>a[i],ins(i);
	getfail();dfs(0);
	for(int i=1;i<=Q;i++){
		l=read(),r=read(),k=read();q[i].l=l,q[i].r=r,q[i].id=i,q[i].k=k;
		h[l-1].pb(mp(i,-1)),h[r].pb(mp(i,1));
	}
	for(int i=1;i<=n;i++){
		for(int j=0,now=0;j<len[i];j++)now=ch[now][a[i][j]-'a'],add(L[now],1);
		for(auto j:h[i]){int u=q[j.fi].k;ans[j.fi]+=j.se*(query(R[b[u]])-query(L[b[u]]-1));}
	}
	for(int i=1;i<=Q;i++)printf("%lld\n",ans[i]);
 	return 0;
}