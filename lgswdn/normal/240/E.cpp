#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e5+9;
vi e0[N],ans;
vp e1[N];
int n,m,in[N];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read(), w=read();
		if(w==0) e0[u].emplace_back(v);
		else e1[u].emplace_back(pii(v,i));
	}
	queue<int>q; q.push(1); in[1]=-1;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(auto v:e0[u]) if(in[v]!=-1) in[v]=-1, q.push(v);
		for(auto ed:e1[u]) if(in[ed.fi]==0) in[ed.fi]=ed.se, q.push(ed.fi);
	}
	rep(i,1,n) {
		if(!in[i]) return puts("-1"), 0;
		else if(in[i]!=-1) ans.emplace_back(in[i]);
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d ",x); if(ans.size()) puts("");
	return 0;
}