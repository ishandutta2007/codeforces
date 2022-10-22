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
string s;
int cnt[26];
int n;

int check(string s) {
	for(int i = 0; i < n; i++) if(s[i] != s[n - 1 - i]) return 0;
	return 1;
}

int main() {
	cin >> s;
	n = s.length();
	for(int i = 0; i < n; i++) cnt[s[i] - 'a']++;
	int c0 = 0;
	for(int i = 0; i < 26; i++) if(cnt[i]) c0 += ((cnt[i] - (cnt[i] & 1)) > 0);
	if(c0 <= 1) cout << "Impossible" << endl, exit(0);
	string t = s;
	for(int i = 1; i < n; i++) {
		rotate(s.begin(), s.begin() + 1, s.end());
		if(s == t) continue;
		if(!check(s)) continue;
		cout << 1 << endl;
		exit(0);
	}
	cout << 2 << endl;
	return 0;
}