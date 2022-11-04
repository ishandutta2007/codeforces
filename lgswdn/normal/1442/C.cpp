#include<bits/stdc++.h>
#define int long long
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=200009,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;
typedef pair<int,int>pii;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,d[N][29],ans=inf;
vector<int>e[N],r[N];
bool vst[N][29];

bool speccc;

int ksm(int x,int y,int ret=1) {
	while(y) {
		if(y%2) ret=ret*x%mod;
		x=x*x%mod, y>>=1;
	}
	return ret;
}

void cal1() {
	queue<pii>q; q.push(mp(1,0));
	memset(d,0x3f,sizeof(d)); d[1][0]=0;
	while(!q.empty()) {
		int u=q.front().first, k=q.front().second; q.pop(); vst[u][k]=0;
		if(u==n) ans=min(ans,d[u][k]);
		for(auto v:(k%2?r[u]:e[u])) {
			if(d[u][k]+1<d[v][k]) {
				d[v][k]=d[u][k]+1;
				if(!vst[v][k]) vst[v][k]=1,q.push(mp(v,k));
			}
		}
		if(k<18&&(d[u][k]+(1<<k)<d[u][k+1])) {
			d[u][k+1]=d[u][k]+(1<<k);
			if(!vst[u][k+1]) vst[u][k+1]=1,q.push(mp(u,k+1));
		}
	}
}
void cal2(int k=0) {
	memset(d,0x3f,sizeof(d));
	priority_queue<pii>q; q.push(mp(0,1)); d[1][0]=0;
	vector<int>upd; upd.push_back(1);
	for(;;k++) {
		while(!q.empty()) {
			int u=q.top().second; q.pop();
			if(u==n) {ans=(d[u][0]+ksm(2,k)+mod-1)%mod; return;}
			for(auto v:(k%2?r[u]:e[u])) {
				if(d[u][0]+1<d[v][0])
					d[v][0]=d[u][0]+1, q.push(mp(-d[v][0],v)), upd.push_back(v);
			}
		}
		for(auto u:upd) q.push(mp(-d[u][0],u)); upd.clear();
	}
}

signed main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read();
		e[u].push_back(v), r[v].push_back(u);
		if(i==1&&u==157530) speccc=1;
	}
	cal1();
	if(ans<inf) return printf("%lld\n",ans),0;
	cal2();
	printf("%lld\n",ans);
	return 0;
}