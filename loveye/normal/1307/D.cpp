#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5,M=N;
int n,m,k,a[N];
int fir[N],to[M<<1],nxt[M<<1],eds;
int A[N],B[N];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
void bfs(int s,int* d) {
	queue<int> q;
	fr(i,1,n) d[i]=-1;
	d[s]=0; q.push(s);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		foredge(i,u,v) if(d[v]==-1)
			d[v]=d[u]+1,q.push(v);
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	fr(i,1,k) scanf("%d",a+i);
	for(int i=1,u,v;i<=m;++i) {
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	bfs(1,A); bfs(n,B);
	int res1=0,res2=0,ans1=0,ans2=0;
	sort(a+1,a+k+1,[](const int &i,const int &j) {
		return A[i]-B[i]<A[j]-B[j];
	});
	int ans=0,resb=0;
	rf(i,k,1) {
		if(i!=k) ans=max(ans,A[a[i]]+resb+1);
		resb=max(resb,B[a[i]]);
	}
	printf("%d\n",min(A[n],ans));
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}