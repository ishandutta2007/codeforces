#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
int n;
string s[3];
vector<string> c[2];

string con(string a, string b, int k) {
	string ans = "";
	int n1 = 0, n2 = 0;
	while(n1 < n * 2 || n2 < n * 2) {
		int c1 = 0, c2 = 0;
		while(n1 < n * 2 && a[n1] - '0' != k) n1++, c1++;
		while(n2 < n * 2 && b[n2] - '0' != k) n2++, c2++;
		for(int i = 1; i <= max(c1, c2); i++) ans += (char)('0' + (k ^ 1));
		if(n1 < n * 2 || n2 < n * 2) ans += (char)('0' + k);
		if(n1 < n * 2 && a[n1] - '0' == k) n1++;
		if(n2 < n * 2 && b[n2] - '0' == k) n2++;
	}
	return ans;
}

void work() {
	cin >> n;
	c[0].clear(), c[1].clear();
	for(int i = 0; i < 3; i++) {
		cin >> s[i];
		int c0 = 0;
		for(int j = 0; j < 2 * n; j++) if(s[i][j] == '0') c0++;
		c[c0 < n].push_back(s[i]);
	}
	if(c[0].size() >= 2) cout << con(c[0][0], c[0][1], 0) << endl;
	else cout << con(c[1][0], c[1][1], 1) << endl;
	return;
}

int main() {
	int T;
	cin >> T;
	for(; T--; work());
	return 0;
}