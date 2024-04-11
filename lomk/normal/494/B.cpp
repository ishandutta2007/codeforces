/*input
ddd
d



ababa
aba
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 100005;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}

const int B1 = 72, B2 = 59, M1 = 1500450271, M2 = 1e9 + 9;

int h1[N], h2[N], p1[N], p2[N];
void prepHash(string s) {
	p1[0] = 1; p2[0] = 1;
	for (int i = 1; i <= s.size(); i++) {
		p1[i] = (p1[i - 1] * B1) % M1;
		p2[i] = (p2[i - 1] * B2) % M2;
	}
	for (int i = 1; i <= s.size(); i++) {
		h1[i] = (h1[i - 1] * B1 + s[i - 1]) % M1;
		h2[i] = (h2[i - 1] * B2 + s[i - 1]) % M2;
	}
}

pair<int, int> get(int L, int R) {
	int len = R - L + 1;
	int ans1 = (h1[R] - h1[L - 1] * p1[len]) % M1;
	if (ans1 < 0) ans1 += M1;
	int ans2 = (h2[R] - h2[L - 1] * p2[len]) % M2;
	if (ans2 < 0) ans2 += M2;
	return mp(ans1, ans2);
}

bool mark[N];
int dp[N]; int sum[N];
const int mod = 1e9 + 7;

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	string S, T;
	cin >> S >> T;
	prepHash(T);
	auto hashT = get(1, T.size());
	prepHash(S);
	loop(i, 1, S.size()) {
		if (i < T.size()) continue;
		if (get(i - T.size() + 1, i) == hashT) mark[i] = true;
	}
	int last = -1;
	dp[0] = 1; sum[0] = 1;
	loop(i, 1, S.size()) {
		if (mark[i]) last = i - T.size();
		dp[i] = dp[i - 1];
		if (last != -1) {
			dp[i] += sum[last];
		}
		sum[i] = sum[i - 1] + dp[i];
		dp[i] %= mod; sum[i] %= mod;
	}
	int ans = dp[S.size()] - 1;
	ans %= mod; if (ans < 0) ans += mod;
	cout << ans << endl;
}