#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 3e5 + 100;
const int mod1 = 998244353;
const int mod2 = 1e9 + 7;
const int T = 20;
pair <ll, ll> h[T][N];
int nxt[T][N];
int start_idx[N];
int len_string[N];
int maxlen[N];
string s;
int n;
int pow1[N], pow2[N];
int compare(int first, int second) {
	int minl = min(len_string[first], len_string[second]);
	//cout << minl << "\n";
	for (int j = 20; j >= 0; j--) {
		if ((1 << j) > minl) {
			continue;
		}
		if (h[j][first] == h[j][second]) {
			first = nxt[j][first];
			second = nxt[j][second];
		}
	}
//	cout << first << " " << second << "\n";
	if (first == n || first != n && s[first] == '(') {
		return 1;
	}
	return 0;
}
void calculate(int i) {
	int len = len_string[i];
	h[0][i] = {(s[i] == ')') + 1, (s[i] == ')') + 1};
	for (int j = 1; (1 << j) <= len; j++) {
		nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
		h[j][i].x = (1LL * pow1[1 << (j - 1)] * h[j - 1][i].x % mod1 + h[j - 1][nxt[j - 1][i]].x) % mod1;
		h[j][i].y = (1LL * pow2[1 << (j - 1)] * h[j - 1][i].y % mod2 + h[j - 1][nxt[j - 1][i]].y) % mod2;
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i < N; i++) {
		pow1[i] = 1LL * pow1[i - 1] * 3 % mod1;
		pow2[i] = 1LL * pow2[i - 1] * 3 % mod2;
	}
	cin >> s;
	n = sz(s);
	vector <pair <char, int> > st;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			st.push_back({s[i], i});
		}
		else if(sz(st) != 0 && st.back().x == '(') {
			maxlen[st.back().y] = i - st.back().y + 1;
			st.pop_back();
		}
		else {
			st.push_back({s[i], i});
		}
	}
	if (maxlen[0] == n) {
		cout << "";
		return 0;
	}
	start_idx[n] = n;
	len_string[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
//		cout << "A " << i << "\n";
		int l = maxlen[i];
		nxt[0][i] = start_idx[i + 1];
		len_string[i] = len_string[nxt[0][i]] + 1;
		calculate(i);
		start_idx[i] = i;
		if (l != 0) {
			if (compare(start_idx[i + l], i)) {
				start_idx[i] = start_idx[i + l];
			}
 		}
 //		cout << start_idx[i] << "\n";
	}
	int j = start_idx[0];
	while (j < n) {
		cout << s[j];
		j = nxt[0][j];
	}
	return 0;
}