#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=6e5+9;
typedef pair<int,int> pii;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,x,a[N],deg[N],l,r,ans[N],sum;
vector<pii>e[N];
bool del[N];

int id[N];
int find(int i) {return i==id[i]?i:id[i]=find(id[i]);}
void merge(int u,int v) {id[find(u)]=find(v);}
	
void cfs(int u,int fa) {
	del[u]=1;
	for(auto edge:e[u]) {
		int v=edge.first, id=edge.second;
		if(del[v]) continue;
		cfs(v,u);
		if(a[u]+a[v]>=x) a[u]+=a[v]-x, ans[l++]=id;
		else ans[r--]=id;
	}
}

signed main() {
	n=read(), m=read(), x=read();
	rep(i,1,n) a[i]=read(), id[i]=i, sum+=a[i];
	l=1, r=n-1;
	rep(i,1,m) {
		int u=read(), v=read();
		e[u].push_back(pii(v,i)), e[v].push_back(pii(u,i));
		deg[u]++, deg[v]++;
	}
	if(sum<(n-1)*x) return puts("NO"), 0;
	cfs(1,0);
	puts("YES");
	rep(i,1,n-1) printf("%d\n",ans[i]);	
	return 0;
}