#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9,base=10;
typedef pair<int,int> pii;
typedef unsigned long long ull;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,k,ans;
vector<pii>e[N];
vector<int>rg[N];
ull p[N],s[19][19],all;

void dfs(int pos,ull hsh) {
	if(pos==k+1) {ans+=(hsh==all); return;}
	rep(i,1,pos) {
		dfs(pos+1,hsh+s[pos][i]);
	}
}

int main() {
	n=read(), m=read(), k=read();
	p[0]=1; rep(i,1,n) p[i]=p[i-1]*base,all+=p[i];
	rep(i,1,m) {
		int u=read(), v=read(), w=read();
		e[u].push_back(make_pair(w,v));
	}
	rep(u,1,n) sort(e[u].begin(),e[u].end());
	rep(i,1,n) rg[e[i].size()].push_back(i);
	rep(i,1,k) rep(j,1,i) {
		for(auto u:rg[i]) s[i][j]+=p[e[u][j-1].second];
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}