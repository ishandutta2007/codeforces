// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

int n, p;

bool o = 0;

bool st[26], cur[26];

void inline chk() {
	int c = 0;
	for (int i = 0; i < 26; i++)
		if (!st[i]) ++c, p = i;
	if (c == 1) o = 1;
}

int main() {
	cin >> n; int ans = 0;
	while (n--) {
		string op, a; cin >> op >> a;
		if (op == "!") {
			memset(cur, 0, sizeof cur);
			for (char c: a) {
				cur[c - 'a'] = 1;
			}
			for (int i = 0; i < 26; i++)
				if (!cur[i]) st[i] = 1;
			if (o) {
				for (char c: a) {
					if (c - 'a' == p) {
						++ans;
						break;	
					}
				}
			}
		} else if (op == "."){
			for (char c: a)
				st[c - 'a'] = 1;
		} else {
			int t = a[0] - 'a';
			if (o && t != p) {
				++ans;
			}
			st[t] = 1;
		}
		chk();
	}
	cout << ans;
    return 0;
}