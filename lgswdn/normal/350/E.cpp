#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=309;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,k;
bool e[N][N],tag[N];
vector<int>a,b;

int main() {
	n=read(), m=read(), k=read();
	rep(i,1,k) {
		int x=read();
		tag[x]=1, a.push_back(x);
	}
	rep(i,1,n) if(!tag[i]) b.push_back(i);
	if(k==n||m>(n-1)*(n-2)/2-k+n) {
		puts("-1");
		return 0;
	}
	for(auto u:b) printf("%d %d\n",a[0],u), m--, e[a[0]][u]=e[u][a[0]]=1;
	for(auto u:a) if(u!=a[0]) printf("%d %d\n",b[0],u), m--, e[b[0]][u]=e[u][b[0]]=1;
	for(auto u:b) for(auto v:b) if(u!=v&&m&&!e[u][v]) printf("%d %d\n",u,v), m--, e[u][v]=e[v][u]=1;
	if(!m) return 0;
	for(auto u:a) for(auto v:b) if(m&&u!=a[0]&&!e[u][v]) printf("%d %d\n",u,v), m--, e[u][v]=e[v][u]=1;
	if(!m) return 0;
	for(auto u:a) for(auto v:a) if(m&&u!=v&&u!=a[0]&&v!=a[0]&&!e[u][v]) printf("%d %d\n",u,v), m--, e[u][v]=e[v][u]=1;
	return 0;
}