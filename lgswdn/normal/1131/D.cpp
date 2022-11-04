#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,d[N],f[N],cnt;
char c[N][N];
vector<int>e[N];
void add(int u,int v) {e[u].push_back(v); d[v]++;}

int id[N]; //dsu
int find(int i) {return i==id[i]?i:id[i]=find(id[i]);}

void topo() {
	queue<int>q;
	rep(i,1,n+m) if(i==find(i)&&!d[i]) q.push(i),f[i]=1;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(auto v:e[u]) {
			f[v]=max(f[v],f[u]), d[v]--;
			if(d[v]==0) f[v]++, q.push(v);
		}
	}
}

int main() {
	n=read(), m=read();
	rep(i,1,n) scanf("%s",c[i]+1);
	rep(i,1,n+m) id[i]=i;
	bool flag=0;
	rep(i,1,n) rep(j,1,m) {
		int u=find(i), v=find(j+n);
		if(c[i][j]!='='&&u==v) {flag=1; break;}
		else if(c[i][j]=='=') id[u]=v;
	}
	if(flag==1) return puts("No"), 0;
	rep(i,1,n+m) if(find(i)==i) cnt++;
	rep(i,1,n) rep(j,1,m) {
		int u=find(i), v=find(j+n);
		if(c[i][j]=='<') add(u,v);
		else if(c[i][j]=='>') add(v,u);
	}
	topo();
	rep(i,1,n+m) if(i==find(i)&&d[i]) {flag=1; break;}
	if(flag==1) return puts("No"), 0;
	puts("Yes");
	rep(i,1,n) printf("%d ",f[find(i)]); puts("");
	rep(i,1,m) printf("%d ",f[find(i+n)]); puts("");
	return 0;
}