#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 105;
int t,n,p[N],cmp[N],q[N];
inline int ask1(int a,int b) {
	static int res;
	cout << 1 << ' ' << a << ' ' << b << endl;
	cin >> res;
	return res;
}
void solve(int l,int r) {
	if(l == r-1) return p[l] = l,void();
	int mid = l + r >> 1;
	solve(l,mid); solve(mid,r);
	int p1 = l,p2 = mid,p3 = l;
	while(p1 < mid || p2 < r) {
		if(p1 == mid || (p2 < r && ask1(p[p2],p[p1]))) q[p3++] = p[p2++];
		else q[p3++] = p[p1++];
	}
	fo(i,l,r) p[i] = q[i];
}
inline int ask2(int x,int l,int r) {
	static int res;
	cout << 2 << ' ' << x << ' ' << r-l+1 << ' ';
	fr(i,l,r) cout << p[i] << ' ';
	cout << endl;
	cin >> res;
	return res;
}
bool vis[N];
I work() {
	fo(i,0,n) vis[i] = 1;
	for(int l = n-1,r = n-1;r >= 0 && l >= 0;--r) {
		l = min(l,r-1);
		if(ask2(p[r],0,l)) {
			do vis[l+1] = 0,--l;
			while(l >= 0 && ask2(p[r],0,l));
		}
	}
	int cnt = 1;
	fo(i,0,n) cnt += vis[i],cmp[p[i]] = cnt;
}
I chkans() {
	static int res;
	cin >> res;
	if(res == -1) exit(1);
}
int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> n;
		solve(0,n);
		work();
		cout << 3 << endl;
		fo(i,0,n) {
			fo(j,0,n) cout << (cmp[i] <= cmp[j]);
			cout << endl;
		}
		chkans();
	}
	return 0;
}