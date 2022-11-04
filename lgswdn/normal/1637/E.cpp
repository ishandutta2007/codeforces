#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define jmp(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define pmj(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=5e5+9;
int n,a[N],b[N],m;
map<int,int>c,r;
set<int>s[N];
vi f[N];
vi p;

signed main() {
	int T=read();
	while(T--) {
		n=read(), m=read();
		c.clear(), r.clear();
		rep(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
		rep(i,1,n) c[a[i]]++;
		int cnt=unique(a+1,a+n+1)-a-1;
		rep(i,1,cnt) b[i]=c[a[i]], r[a[i]]=i;
		rep(i,1,cnt) f[i].clear(), f[i].shrink_to_fit();
		rep(i,1,m) {
			int x=read(), y=read();
			f[r[x]].emplace_back(r[y]), f[r[y]].emplace_back(r[x]);
		}
		rep(i,1,n) s[i].clear();
		rep(i,1,cnt) s[b[i]].insert(a[i]);
		p.clear(), p.shrink_to_fit();
		rep(i,1,n) if(s[i].size()) p.emplace_back(i);
		int ans=0;
		rep(i,1,cnt) {
			for(auto x:f[i]) s[b[x]].erase(a[x]); s[b[i]].erase(a[i]);
			for(auto x:p) if(s[x].size()) ans=max(ans,(a[i]+*--s[x].end())*(x+b[i]));
			for(auto x:f[i]) s[b[x]].insert(a[x]); s[b[i]].insert(a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}