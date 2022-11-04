#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=2e5+9;
int T,n,deg[N],ans,m,q;

void add(int u) {
	if(deg[u]==0) ans--;
	deg[u]++;
}
void del(int u) {
	if(deg[u]==1) ans++;
	deg[u]--;
}

signed main() {
	n=read(), m=read();
	ans=n;
	rep(i,1,m) {
		int u=read(), v=read();
		if(u<v) add(u); else add(v);
	}
	q=read();
	rep(i,1,q) {
		int opt=read();
		if(opt==1) {
			int u=read(), v=read();
			if(u<v) add(u); else add(v);
		} else if(opt==2) {
			int u=read(), v=read();
			if(u<v) del(u); else del(v);
		} else printf("%lld\n",ans);
	}
	return 0;
}