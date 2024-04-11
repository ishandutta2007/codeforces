#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int N, K;

int get_sum(vector <int> &a) {
	int s = 0;
	for(int e : a) s += e;
	return s;
}

vector <int> Nxt(vector <int> a) {
	if(get_sum(a) > N) return {};
	vector <int> res;
	for(int i=szz(a)-1, t=0;i>=0;i--) {
		++t;
		rep(j, a[i]) res.pb(t);
	}
	return res;
}

int get_o(vector <int> w) {
	for(int k=0;;k++) {
		w = Nxt(w);
		if(szz(w) == 0) {
			return k;
		}
	}
}

int cnt;
const int mod = 998244353;

void Gen(vector <int> t) {
	if(szz(t) && !(szz(t) == 1 && t[0] == 1) && get_o(t) < K) return;
	if(szz(t)) ++cnt;
	int l = szz(t) ? t.back() : 1;
	for(int i=l;i<=100;i++) {
		t.pb(i);
		Gen(t);
		t.pop_back();
	}
}

void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}

const int MAXN = 2020;
int dp1[2100][2100];
map <t3, int> Mx;

inline int f(int x) {
	return x * (x+1) / 2;
}
int Do2(int x, int s, int res) {
	if(Mx.find(t3(x, s, res)) != Mx.end()) return Mx[t3(x, s, res)];
	int v = 1;
	for(int i=x;res+f(s+i)<=N;i++) {
		add(v, Do2(i, s+i, res+f(s+i)));
	}
	return Mx[t3(x, s, res)] = v;
}

int dp[2100][2100];
int Do1(int n, int x) {
	if(dp[n][x] != -1) return dp[n][x];
	int res = 1;
	for(int i=x;f(i)<=n;i++) {
		add(res, Do1(n - f(i), i));
	}
	return dp[n][x] = res;
}

int main() {
	scanf("%d%d", &N, &K);
	if(K >= 12) {
		puts("1");
	}
	else if(K >= 4) {
		vector <int> w = {};
		Gen(w);
		printf("%d\n", cnt);
	}
	else if(K == 1) {
		dp1[0][0] = 1;
		for(int i=1;i<=MAXN;i++) {
			for(int j=0;j<=MAXN;j++) {
				for(int x=0;x*i<=j;x++) {
					add(dp1[i][j], dp1[i-1][j-x*i]);
				}
			}
		}
		int ans = 0;
		for(int n=1;n<=N;n++) {
			for(int i=1;i<=n;i++) {
				add(ans, dp1[i][n-i]);
			}
		}
		printf("%d\n", ans);
	}
	else if(K == 2) {
		int ans = 0;
		memset(dp, -1, sizeof dp);
		for(int x=1;f(x)<=N;x++) {
			add(ans, Do1(N - f(x), x));
		}
		printf("%d\n", ans);
	}
	else if(K == 3) {
		int ans = 0;
		for(int x=1;f(x)<=N;x++) {
			add(ans, Do2(x, x, f(x)));
		}
		printf("%d\n", ans);
	}
	return 0;
}