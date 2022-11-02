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
const int maxn=2e5+5,M=2e5+5,mod=998244353,inf=1e9;
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
int n,m,a[maxn],b[maxn],tot=0,ans[maxn],c[maxn];
int sz[maxn],Rt,x,y;vector<int>e[maxn];
struct node{
	multiset<int>s;
	void add(int x){s.insert(x);}
	void del(int x){s.erase(s.find(x));}
	int lower(int x){
		auto it=s.lower_bound(x);
		if(it==s.end())return inf;
		else return *it;
	}
	int get(int mx2,int mx,int mn,int z){
		int l=mx2,r=mx;int res=mx;
		while(l<=r){
			if(lower(mx+z-mid)<=z-mn+mid)res=mid,r=mid-1;
			else l=mid+1;
		}
		return res;
	}
}anc,out,in;
void dfs(int x,int fa){
	sz[x]=1;
	for(auto i:e[x])if(i^fa){
		dfs(i,x),sz[x]+=sz[i];
	}out.add(sz[x]);
}
void add(int x,int fa){
	in.add(sz[x]);out.del(sz[x]);
	for(auto i:e[x])if(i^fa)add(i,x);
}
void del(int x,int fa){
	out.add(sz[x]);in.del(sz[x]);
	for(auto i:e[x])if(i^fa)del(i,x);
}
void solve(int x,int fa){
	
	anc.add(sz[x]);
	out.del(sz[x]);
	in.add(sz[x]);
	int son=0,son2=0,mn=n;
	for(auto i:e[x])if(i!=fa){
		if(sz[son2]<sz[i])son2=i;
		if(sz[son2]>sz[son])swap(son,son2);
		mn=min(mn,sz[i]);
	}
	ans[x]=max(n-sz[x],sz[son]);
	if(fa)mn=min(mn,n-sz[x]);
	for(auto i:e[x])if(i!=fa&&i!=son)solve(i,x),del(i,x);
	if(son)solve(son,x);
	if(sz[son]>n-sz[x]){
		ans[x]=min(ans[x],in.get(max(sz[son2],n-sz[x]),sz[son],mn,0));
	}
	for(auto i:e[x])if(i!=fa&&i!=son)add(i,x);
	if(n-sz[x]>sz[son]){
		ans[x]=min(ans[x],anc.get(sz[son],n-sz[x],mn,sz[x]));
		ans[x]=min(ans[x],out.get(sz[son],n-sz[x],mn,0)); 
	} 
	anc.del(sz[x]);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		x=read(),y=read();
		if(!x||!y)Rt=x+y;
		else e[x].pb(y),e[y].pb(x);
	}dfs(Rt,0);
	solve(Rt,0);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
 	return 0;
}