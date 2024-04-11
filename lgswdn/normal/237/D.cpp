#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=5e5+9;

int n;
vector<pii>e[N];

void dfs(int u,int fa,int id) {
	for(auto ed:e[u]) {
		int v=ed.fi, d=ed.se;
		if(v==fa) continue;
		if(id) printf("%d %d\n",id,d);
		id=d;
		dfs(v,u,id);
	}
}

int main() {
	n=read();
	printf("%d\n",n-1);
	rep(i,1,n-1) {
		int u=read(), v=read();
		printf("2 %d %d\n",u,v);
		e[u].emplace_back(pii(v,i));
		e[v].emplace_back(pii(u,i));
	}
	dfs(1,0,0);
	return 0;
}