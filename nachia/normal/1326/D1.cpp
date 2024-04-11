#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

// Suffix Array
void initSA(
	const string& S,
	vector<int>& oRank,
	vector<int>& oSA)
{
	int N = S.size();
	oRank.resize(N + 1);
	oSA.resize(N + 1);
	vector<int> Rtmp(N + 1);
	rep(i, N) oRank[i] = S[i];
	oRank[N] = -1;
	int L = 1;
	while (L < N || L == 1) {
		auto cmpi = [N, L, &oRank](int l, int r)->bool {
			if (oRank[l] != oRank[r]) return oRank[l] < oRank[r];
			return oRank[min(N, l + L)] < oRank[min(N, r + L)];
		};
		rep(i, N + 1) oSA[i] = i;
		sort(oSA.begin(), oSA.end(), cmpi);
		rep(i, N + 1) Rtmp[i] = 0;
		Rtmp[oSA[0]] = 0;
		for (int i = 1; i <= N; i++)
			Rtmp[oSA[i]] = Rtmp[oSA[i - 1]] + (cmpi(oSA[i - 1], oSA[i]) ? 1 : 0);
		rep(i, N + 1) oRank[i] = Rtmp[i];
		L <<= 1;
	}
	rep(i, N + 1) oSA[oRank[i]] = i;
}

// Longest Common Prefix of Suffixes
void initSA_LCP(
	const string& S,
	const vector<int>& Rank,
	const vector<int>& SA,
	vector<int>& oLCP)
{
	int N = S.size();
	oLCP.resize(N);
	int h = oLCP[0] = 0;
	rep(i, N) {
		int p = SA[Rank[i] - 1];
		if (h) h--;
		for (; max(p + h, i + h) < N; h++)
			if (S[p + h] != S[i + h]) break;
		oLCP[Rank[i] - 1] = h;
	}
}

struct RMQ {
	int N;
	vector<int> V;
	void init(int n) {
		N = 1; while (N < n) N <<= 1;
		V.resize(N * 2);
	}
	int query(int l, int r, int a = 0, int b = 0, int i = -1) {
		if (i == -1) { a = 0; b = N; i = 1; }
		if (r <= a || b <= l) return INT_MAX;
		if (l <= a && b <= r) return V[i];
		int q1 = query(l, r, a, (a + b) >> 1, i << 1);
		int q2 = query(l, r, (a + b) >> 1, b, (i << 1) + 1);
		return min(q1, q2);
	}
	void upd(int p, int v) {
		p += N; V[p] = v;
		while (p != 1) {
			p >>= 1;
			V[p] = min(V[p << 1], V[(p << 1) + 1]);
		}
	}
};

string S;
vector<int> SA;
vector<int> saRank;
vector<int> saLCP;
RMQ G;
string ans;

void loop() {
	cin >> S;
	int X = 0;
	while (S.size() - X * 2 >= 2)
		if (S[X] == S[S.size() - 1 - X]) X++;
		else break;
	ans = S.substr(0, X);
	S = S.substr(X, S.size() - X - X);

	int N = S.size();
	S = S + "$" + S;
	reverse(S.begin(), S.begin() + N);
	initSA(S, saRank, SA);
	initSA_LCP(S, saRank, SA, saLCP);
	G.init(saLCP.size());
	rep(i, saLCP.size()) G.upd(i, saLCP[i]);

	int len = 0, lp = 0, rp = 0;
	rep(i, N + 1) {
		int lq, rq;

		lq = i / 2, rq = N + 1 + N - (i + 1) / 2;
		if (G.query(min(saRank[lq], saRank[rq]), max(saRank[lq], saRank[rq])) >= (i + 1) / 2) {
			len = i; lp = lq; rp = rq;
		}
		lq = N - (i + 1) / 2, rq = N + 1 + i / 2;
		if (G.query(min(saRank[lq], saRank[rq]), max(saRank[lq], saRank[rq])) >= (i + 1) / 2) {
			len = i; lp = lq; rp = rq;
		}
	}

	ans += S.substr(lp - len / 2, (len + 1) / 2);
	ans += ans.substr(0, ans.size() - len % 2);
	reverse(ans.begin() + (ans.size() + 1) / 2, ans.end());
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) loop();
	return 0;
}