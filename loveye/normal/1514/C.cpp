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

const int N = 1e5 + 5;
int n;
vector<int> ans;
int gcd(int x,int y) {
	return !y ? x : gcd(y,x % y);
}
/*
void exgcd(int a,int b,int &x,int &y) {
	if(!b) return x = 1,y = 0,void();
	exgcd(b,a % b,y,x);
	y -= a/b * x;
}
inline int inv(int x) {
	int a,b;
	exgcd(x,n,a,b);
	return (a % n + n) % n;
}
*/
bool vis[N],mark[N];
int main() {
	cin >> n;
	vis[1] = 1;
	fo(i,2,n) if(gcd(i,n) == 1) {
		if(1ll * i * i % n == 1) mark[i] = 1;
		else vis[i] = 1;
	}
	LL A = n-1;
	fo(i,2,n-1) if(mark[i] && !vis[i]) {
		if(vis[A]) {
			vis[A] = 0;
			vis[i] = vis[1ll * A * i % n] = 1;
		} else {
			vis[A] = 1;
			vis[i] = vis[1ll * A * i % n] = 1;
		}
	}
	fo(i,1,n) if(vis[i]) ans.push_back(i);
	cout << ans.size() << endl;
	fo(i,0,ans.size()) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}