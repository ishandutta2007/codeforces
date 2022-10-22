#include<bits/stdc++.h>
using namespace std;

int read();
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

const int N = 35005,K = 105;
int n,k,a[N],id;
LL dp[K][N];
deque<int> pos[N];
int x,y,ans;
void solve(int l,int r,int L,int R) {
	int mid = l + r >> 1,p;
	while(y < mid) {
		++y;
		if(pos[a[y]].size()) ans += y - pos[a[y]].back();
		pos[a[y]].push_back(y);
	}
	while(x > L) {
		--x;
		if(pos[a[x]].size()) ans += pos[a[x]].front() - x;
		pos[a[x]].push_front(x);
	}
	while(y > mid) {
		pos[a[y]].pop_back();
		if(pos[a[y]].size()) ans -= y - pos[a[y]].back();
		--y;
	}
	dp[id][mid] = dp[id-1][x-1] + ans; p = x;
	while(x < mid && x < R) {
		pos[a[x]].pop_front();
		if(pos[a[x]].size()) ans -= pos[a[x]].front() - x;
		++x;
		if(dp[id][mid] > dp[id-1][x-1] + ans) {
			dp[id][mid] = dp[id-1][x-1] + ans;
			p = x;
		}
	}
	if(l <= mid-1) solve(l,mid-1,L,p);
	if(mid+1 <= r) solve(mid+1,r,p,R);
}
int main() {
	cin >> n >> k;
	memset(dp,0x3f,sizeof dp);
	dp[1][0] = 0;
	fr(i,1,n) {
		cin >> a[i];
		if(pos[a[i]].size()) dp[1][i] = dp[1][i-1] + (i - pos[a[i]].back());
		else dp[1][i] = dp[1][i-1];
		pos[a[i]].push_back(i);
	}
	fr(i,2,k) {
		x = 1,y = 0,ans = 0;
		fr(j,1,n) pos[j].clear();
		id = i,solve(1,n,1,n);
		dp[i][0] = 0;
	}
	cout << dp[k][n] << endl;
	return 0;
}