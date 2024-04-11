#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1005;
int n,k;
int G[N][N];
void solve(int l,int r,int dep) {
	if(r-l+1 <= k) {
		fr(i,l,r) fr(j,i+1,r) G[i][j] = dep;
		return;
	}
	int len = (r-l+1) / k,c = (r-l+1) % k;
	int p = l;
	fr(i,1,k) {
		int dt = len + (i <= c);
		solve(p,p+dt-1,dep+1);
		fr(i1,l,p-1) fr(i2,p,p+dt-1)
			G[i1][i2] = dep;
		p += dt;
	}
}
int main() {
	cin >> n >> k;
	solve(1,n,1);
	cout << int(ceil(log(n) / log(k))) << endl;
	fr(i,1,n) fr(j,i+1,n) cout << G[i][j] << ' ';
	cout << endl;
	return 0;
}