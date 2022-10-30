#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

/* Fast Integer IO */
template<typename T> inline T read(T &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<typename T, typename... Args> inline void read(T &x, Args& ...args){
	read(x); read(args...);
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define MAXN 1503

int N, M;
int A[MAXN];

struct SEG{
	int l, r, s;
	bool operator < (const SEG &ot)const{
		return s != ot.s ? s < ot.s : r < ot.r;
	}
};

int main()
{
	read(N);
	for (int i=1;i<=N;i++) read(A[i]);
	vector <SEG> arr;
	for (int i=1;i<=N;i++){
		int s = 0;
		for (int j=i;j<=N;j++){
			s += A[j];
			arr.pb({i, j, s});
		}
	}
	sort(all(arr));
	M = sz(arr);
	vector <int> dp(M), from(M);
	for (int i=0,j=0;i<M;i++){
		auto &sg = arr[i];
		dp[i] = 1; from[i] = -1;
		if (i > 0 && arr[i-1].s == arr[i].s) dp[i] = dp[i-1], from[i] = i-1;
		int x = lower_bound(all(arr), SEG{0, sg.l, sg.s}) - arr.begin() - 1;
		if (x < 0 || arr[x].s != arr[i].s) continue;
		if (dp[i] < dp[x]+1) dp[i] = dp[x]+1, from[i] = x;
	}
	int mx = 0, mxt = -1;
	for (int i=0;i<M;i++){
		if (mx < dp[i]) mx = dp[i], mxt = i;
	}
	vector <SEG> ans;
	for (int i=mxt;i>=0;i=from[i]){
		if (from[i] < 0 || dp[i] == dp[from[i]]+1) ans.pb(arr[i]);
	}
	assert(mx == sz(ans));
	write(sz(ans)); puts("");
	for (auto &sg: ans) write(sg.l), putchar(' '), write(sg.r), puts("");
}