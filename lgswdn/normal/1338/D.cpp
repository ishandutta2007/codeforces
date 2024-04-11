#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,f[N][2],ans;
vector<int>e[N];

void dfs(int u,int fa) {
	for(auto v:e[u]) if(v!=fa) {
		dfs(v,u);
		ans=max(ans,f[u][1]+f[v][0]+1);
		ans=max(ans,f[u][0]+max(f[v][0],f[v][1])+(int)e[u].size()-2);
		f[u][1]=max(f[u][1],f[v][0]);
		f[u][0]=max(f[u][0],max(f[v][0],f[v][1]));
	}
	f[u][1]++;
	if(e[u].size()>=2) f[u][0]+=e[u].size()-2;
	ans=max(ans,max(f[u][0],f[u][1]));
}

int main() {
	n=read();
	rep(i,2,n) {
		int u=read(), v=read();
		e[u].push_back(v), e[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}