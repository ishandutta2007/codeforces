#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e6+9;

int n,m,q,ans;
set<int>s[N];
bool ex[N];

signed main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read();
		s[u].insert(v), s[v].insert(u);
	}
	rep(i,1,n) {
		if(s[i].empty()||*s[i].rbegin()<i) ans++, ex[i]=1;
	}
	q=read();
	rep(i,1,q) {
		int opt=read();
		if(opt==3) printf("%lld\n",ans);
		else if(opt==1) {
			int u=read(), v=read();
			ans-=ex[u], ans-=ex[v], ex[u]=ex[v]=0;
			s[u].insert(v), s[v].insert(u);
			if(s[u].empty()||*s[u].rbegin()<u) ans++, ex[u]=1;
			if(s[v].empty()||*s[v].rbegin()<v) ans++, ex[v]=1;
		} else {
			int u=read(), v=read();
			ans-=ex[u], ans-=ex[v], ex[u]=ex[v]=0;
			s[u].erase(v), s[v].erase(u);
			if(s[u].empty()||*s[u].rbegin()<u) ans++, ex[u]=1;
			if(s[v].empty()||*s[v].rbegin()<v) ans++, ex[v]=1;
		}
	}
	return 0;
}