#include<bits/stdc++.h>
using namespace std;
const int MOD = 0;

const int S = 1 << 21;
char p0[S],*p1,*p2;
#ifndef ZXY
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
#endif
inline int read() {
	static int x,c;x = 0;
	do{c = getchar();}while(!isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();}while(isdigit(c));
	return x;
}

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])

const int N = 1e4 + 5;
int n,vis[N],ans[N];
queue<int> q;
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1;i <= n;++i) q.push(i);
	while(q.size() > 1) {
		int u = q.front();q.pop();
		int v = q.front();q.pop();
		int res1,res2;
		cout << "? " << u << ' ' << v << endl;
		cin >> res1;
		cout << "? " << v << ' ' << u << endl;
		cin >> res2;
		if(res1 < res2) ans[v] = res2;
		else ans[u] = res1;
		if(!ans[u]) q.push(u);
		else q.push(v);
	}
	for(int i = 1;i <= n;++i) vis[ans[i]] = 1;
	for(int i = 1;i <= n;++i) if(!vis[i]) ans[0] = i;
	cout << "!";
	for(int i = 1;i <= n;++i)
		cout << ' ' << (ans[i] ? ans[i] : ans[0]);
	cout << endl;
	return 0;
}