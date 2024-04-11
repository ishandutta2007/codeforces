#include <bits/stdc++.h>
#define i64 long long
#define u64 unsigned long long
#define sz(a) int((a).size())
#define x first
#define y second
#define pb push_back
#define vi vector<int>
#define TP template
using namespace std;
const int N = 200 + 5;
vi g[N];
TP<int N, int M> struct Mat {
	i64 a[N][M];
	Mat() {memset(a, 0xc0, sizeof(a)); }
	Mat(int x) {
		memset(a, 0xc0, sizeof(a));
		for(int i = 0; i < min(N, M); i++) a[i][i] = x;
	}
};

TP<int N, int M, int K> Mat<N, K> operator * (const Mat<N, M> a, const Mat<M, K> b) {
	Mat<N, K> c;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < K; j++) {
			for(int k = 0; k < M; k++) {
				c.a[i][j] = max(c.a[i][j], a.a[i][k] + b.a[k][j]);
			}
		}
	}
	return c;
}

int n, a[N];
int ch[N][26], tot = 1, rt = 1, fail[N], sum[N];
i64 l;

void insert(string &s, int rt, int a) {
	for(int i = 0; i < sz(s); i++) {
		int c = s[i] - 'a';
		if(!ch[rt][c]) ch[rt][c] = ++tot;
		rt = ch[rt][c];
	}
	sum[rt] += a;
	return;
}

void dfs(int u) {
	for(int &v : g[u]) {
		sum[v] += sum[u];
		dfs(v);
	}
	return;
}

void build(int rt) {
	 static queue<int> q;
	 q.push(rt);
	 for(int i = 0; i < 26; i++) ch[0][i] = rt;
	 fail[rt] = 0;
	 while(!q.empty()) {
	 	int u = q.front();
	 	q.pop();
	 	for(int i = 0; i < 26; i++) {
			if(ch[u][i]) {
				fail[ch[u][i]] = ch[fail[u]][i];
				q.push(ch[u][i]);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		 }
	 }
	 for(int i = 2; i <= tot; i++) g[fail[i]].push_back(i);
	 dfs(1);
	 return;
}

Mat<N, N> power(Mat<N, N> a, i64 b) {
	Mat<N, N> c(0);
	for(; b; b >>= 1, a = a * a) 
		if(b & 1)
			c = c * a;
	return c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> l;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		insert(s, rt, a[i]);
	}
	build(rt);
	Mat<N, N> trans;
	for(int i = 1; i <= tot; i++) {
		for(int c = 0; c < 26; c++) {
			int v = ch[i][c];
			if(v) {
				trans.a[i][v] = sum[v];
			}
		}
	}
	trans = power(trans, l);
	i64 ans = 0;
	for(int i = 1; i <= tot; i++) ans = max(ans, trans.a[1][i]);
	cout << ans << endl;
	return 0;
}