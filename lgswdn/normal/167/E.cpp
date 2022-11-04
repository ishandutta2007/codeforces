#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=609;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,mod,id[N],od[N],deg[N],f[N][N],cnt,a[N][N],ans;
vector<int>e[N],s,t;

void topo() {
	queue<int>q;
	rep(i,1,n) if(id[i]==0) q.push(i), f[i][i]=1;
	rep(i,1,n) deg[i]=id[i];
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(auto v:e[u]) {
			for(auto p:s) f[p][v]=(f[p][v]+f[p][u])%mod;
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
}

int gauss(int det=1) {
	rep(i,1,cnt) {
		rep(j,i+1,cnt) {
			if(a[j][i]>a[i][i]) det=-det, swap(a[j],a[i]);
			while(a[j][i]) {
				int b=a[i][i]/a[j][i];
				rep(k,i,cnt) a[i][k]=(a[i][k]+(mod-b)*a[j][k])%mod;
				det=-det, swap(a[j],a[i]);
			}
		}
		det=(det*a[i][i]%mod+mod)%mod;
	}
	return det;
}

signed main() {
	n=read(), m=read(), mod=read();
	rep(i,1,m) {
		int u=read(), v=read();
		id[v]++, od[u]++;
		e[u].push_back(v);
	}
	s.push_back(0), t.push_back(0);
	rep(i,1,n) if(id[i]==0) s.push_back(i), cnt++;
	rep(i,1,n) if(od[i]==0) t.push_back(i);
	topo();
	rep(i,1,cnt) rep(j,1,cnt) a[i][j]=f[s[i]][t[j]];
	ans=gauss();
	printf("%lld\n",ans);
	return 0;
}