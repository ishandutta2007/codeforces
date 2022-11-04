#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,d[N],mx;
vector<int>e[N],fl[N],tmp;
char res[N];

void print(vector<int>v) {
	printf("? %d ",v.size());
	for(auto i:v) printf("%d ",i); puts("");
	fflush(stdout);
}

void dfs(int u,int fa) {
	for(auto v:e[u]) {
		if(v==fa) continue;
		d[v]=d[u]+1, mx=max(mx,d[v]);
		dfs(v,u);
	}
}

int main() {
	T=read();
	while(T--) {
		int n=read();
		rep(i,1,n) e[i].clear();
		rep(i,2,n) {
			int u=read(), v=read();
			e[u].push_back(v), e[v].push_back(u);
		}
		tmp.clear();
		rep(i,1,n) tmp.push_back(i);
		print(tmp);
		int rt=read(), dis=read();
		d[rt]=mx=0;
		dfs(rt,0);
		rep(i,0,n) fl[i].clear();
		rep(i,1,n) fl[d[i]].push_back(i);
		int l=dis/2,r=min(mx,dis),x=0;
		while(l<=r) {
			int mid=(l+r)/2;
			print(fl[mid]);
			int a=read(), da=read();
			if(da==dis) x=a, l=mid+1;
			else r=mid-1;
		}
		d[x]=0;
		dfs(x,0);
		tmp.clear();
		rep(i,1,n) if(d[i]==dis) tmp.push_back(i);
		print(tmp);
		int y=read(), dt=read();
		printf("! %d %d\n",x,y);
		fflush(stdout);
		scanf("%s",res+1);
		if(res[1]!='C') {
			puts("F**k you Mr. interactor.");
			return 0;
		}
	}
	return 0;
}