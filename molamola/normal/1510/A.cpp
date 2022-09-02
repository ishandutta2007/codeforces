#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

using fu = vector<string>;

char S[110];

fu add(fu x, char c) {
	fu res;
	int n = szz(x), m = szz(x[0]), N, M;
	if(c == '+') {
		N = n + 2, M = m + 6;
		res.resize(N);
		rep(i, N) res[i].resize(M);
		rep(i, N) rep(j, M) res[i][j] = ' ';
		rep(i, n) rep(j, m) res[i][3 + j] = x[i][j];
		res[1][0] = '+'; res[1][1] = '-'; res[1][2] = '>';
		res[1][M-1] = '+'; res[1][M-2] = '>'; res[1][M-3] = '-';
		for(int i=0;i<M;i++) res[N-1][i] = '-';
		res[N-1][0] = res[N-1][M-1] = '+';
		res[N-1][1] = '<';
		for(int i=2;i<N-1;i++) res[i][0] = res[i][M-1] = '|';
		return res;
	}
	else if(c == '?') {
		N = n + 3, M = m + 6;
		res.resize(N);
		rep(i, N) res[i].resize(M);
		rep(i, N) rep(j, M) res[i][j] = ' ';
		rep(i, n) rep(j, m) res[3 + i][3 + j] = x[i][j];
		for(int i=0;i<M;i++) res[1][i] = '-';
		res[1][0] = '+'; res[1][M-1] = '+'; res[1][M-2] = '>';
		res[4][0] = res[4][M-1] = '+';
		res[4][1] = res[4][M-3] = '-';
		res[4][2] = res[4][M-2] = '>';
		for(int i=2;i<4;i++) res[i][0] = res[i][M-1] = '|';
		return res;
	}
	else if(c == '*') {
		N = n + 5, M = m + 6;
		res.resize(N);
		rep(i, N) res[i].resize(M);
		rep(i, N) rep(j, M) res[i][j] = ' ';
		rep(i, n) rep(j, m) res[3 + i][3 + j] = x[i][j];
		for(int i=0;i<M;i++) res[1][i] = '-';
		res[1][0] = '+'; res[1][M-1] = '+'; res[1][M-2] = '>';
		res[4][0] = res[4][M-1] = '+';
		res[4][1] = res[4][M-3] = '-';
		res[4][2] = res[4][M-2] = '>';
		for(int i=2;i<4;i++) res[i][0] = res[i][M-1] = '|';
		for(int i=5;i<N-1;i++) res[i][0] = res[i][M-1] = '|';
		res[N-1][0] = res[N-1][M-1] = '+';
		for(int i=1;i<M-1;i++) res[N-1][i] = '-';
		res[N-1][1] = '<';
		return res;
	}
	return res;
}

fu solve(int l, int r) {
	int lev = 0;
	vector <int> sep = {l-1};
	int chk = 0;
	for(int i=l;i<=r;i++) {
		if(S[i] == '(') ++lev;
		if(S[i] == ')') --lev;
		if(lev == 0 && S[i] == '|') sep.pb(i);
		if(i < r && lev == 0) {
			chk = 1;
		}
	}
	if(S[l] == '(' && S[r] == ')' && chk == 0) {
		return solve(l + 1, r - 1);
	}

	sep.pb(r + 1);
	fu ans;
	if(szz(sep) > 2) {
		vector <fu> hh;
		int m = szz(sep);
		for(int i=1;i<m;i++) {
			hh.pb(solve(sep[i-1] + 1, sep[i] - 1));
		}
		int N = szz(hh) - 1, M = 0;
		for(auto &e : hh) {
			N += szz(e);
			M = max(M, szz(e[0]) + 6);
		}
		ans.resize(N);
		rep(i, N) ans[i].resize(M);
		rep(i, N) rep(j, M) ans[i][j] = ' ';
		int sn = 0;
		for(int i=0;i<szz(hh);i++) {
			auto &vv = hh[i];
			int nn = szz(vv), mm = szz(vv[0]);
			rep(j, nn) rep(k, mm) {
				ans[sn + j][3 + k] = vv[j][k];
			}
			ans[sn+1][0] = '+';
			ans[sn+1][1] = '-';
			ans[sn+1][2] = '>';
			for(int k=3+mm;k<=M-3;k++) ans[sn+1][k] = '-';
			ans[sn+1][M-2] = '>';
			ans[sn+1][M-1] = '+';
			if(i + 1 < szz(hh)) for(int j=sn+2;j<=sn+nn+1;j++) ans[j][0] = ans[j][M-1] = '|';
			sn += nn + 1;
		}
		return ans;
	}
	int ok = 1;
	for(int i=l;i<=r;i++) if(!('A' <= S[i] && S[i] <= 'Z')) {
		ok = 0; break;
	}
	if(ok) {
		int len = r - l + 1;
		int N = 3, M = len + 4;
		ans.resize(N);
		rep(i, N) ans[i].resize(M);
		rep(i, N) rep(j, M) ans[i][j] = ' ';
		rep(i, M) ans[0][i] = ans[2][i] = '-';
		rep(i, 3) ans[i][0] = ans[i][M-1] = '+';
		for(int i=2;i<2+len;i++) ans[1][i] = S[l + (i-2)];
		return ans;
	}
	vector <fu> R;
	for(int i=l;i<=r;) {
		if('A' <= S[i] && S[i] <= 'Z') {
			int j = i;
			while('A' <= S[j] && S[j] <= 'Z') ++j;
			if(S[j] == '?' || S[j] == '+' || S[j] == '*') {
				if(j - i > 1) {
					R.pb(solve(i, j - 2));
				}
				R.pb(solve(j-1, j-1));
				i = j;
			}
			else {
				R.pb(solve(i, j - 1));
				i = j;
			}
		}
		else if(S[i] == '?' || S[i] == '+' || S[i] == '*') {
			auto h = R.back(); R.pop_back();
			R.pb(add(h, S[i]));
			++i;
		}
		else if(S[i] == '(') {
			lev = 0;
			for(int j=i;j<=r;j++) {
				if(S[j] == '(') ++lev;
				if(S[j] == ')') --lev;
				if(lev == 0 && S[j] == ')') {
					R.pb(solve(i, j));
					i = j + 1;
					break;
				}
			}
		}
	}
	int m = szz(R);
	int N = 0, M = 2 * (m-1);
	for(auto &hh : R) {
		N = max(N, szz(hh));
		M += szz(hh[0]);
	}
	ans.resize(N);
	rep(i, N) ans[i].resize(M);
	rep(i, N) rep(j, M) ans[i][j] = ' ';
	int sm = 0;
	for(int i = 0; i < m; i++) {
		auto &hh = R[i];
		int nn = szz(hh), mm = szz(hh[0]);
		rep(j, nn) rep(k, mm) ans[j][sm + k] = hh[j][k];
		sm += mm + 2;
		if(i < m - 1) {
			ans[1][sm-1] = '>';
			ans[1][sm-2] = '-';
		}
	}
	return ans;
}

int main() {
	scanf("%s", S + 1);
	int n = (int)strlen(S + 1);
	auto ans = solve(1, n);
	printf("%d %d\n", szz(ans), szz(ans[0]) + 6);
	rep(i, szz(ans)) {
		auto s = ans[i];
		auto t = "   " + s + "   ";
		if(i == 1) t = "S->" + s + "->F";
		printf("%s\n", t.c_str());
	}
	return 0;
}