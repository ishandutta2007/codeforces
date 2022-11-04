#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=100009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,d[N],td[N];
vector<int>e[N];

void topo() {
	queue<int>q;
	rep(i,1,n) if(!d[i]) q.push(i);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(auto v:e[u]) {
			d[v]--;
			if(d[v]==0) q.push(v);
		}
	}
}

int main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read();
		e[u].push_back(v), d[v]++;
	}
	topo();
	rep(i,1,n) td[i]=(d[i]==0?-1:d[i]);
	bool ans=1;
	rep(i,1,n) if(td[i]>0) ans=0;
	if(ans==1) {
		puts("YES");
		return 0;
	}
	rep(i,1,n) if(td[i]==1) {
		rep(j,1,n) d[j]=td[j];
		d[i]--;
		topo();
		bool flag=1;
		rep(i,1,n) if(d[i]>0) flag=0;
		if(flag==1) {
			ans=1;
			break;
		}
	}
	if(ans==1) puts("YES");
	else puts("NO");
	return 0;
}