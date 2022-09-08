#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1005;

string str;
int a[50], used[N], tmp[N], res[N];
int T, n, k, len, len2, len3;

int query() {
	cin >> str;
	if (str == "FIRST") return 1;
	if (str == "SECOND") return 2;
	if (str == "EQUAL") return 3;
	assert(0);
}

inline int R() { return (rand() << 15) ^ rand(); }

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		memset(used, 0, sizeof(used));
		cin >> n >> k;
		if (n == 2) {
			cout << "? 1 1" << endl << 1 << endl << 2 << endl;
			int ans = query();
			if (ans == 1) cout << "! 2" << endl;
			else cout << "! 1" << endl;
			continue;
		}
		int mx = min(n, 31); len = 0;
		for (int i = 1; i <= mx; i++) {
			int x = R() % n + 1;
			while (used[x]) x = R() % n + 1;
			used[x] = 1; a[++len] = x;
		}
		int now = a[1];
		for (int i = 2; i <= mx; i++) {
			cout << "? 1 1" << endl;
			cout << now << endl;
			cout << a[i] << endl;
			int ans = query();
			if (ans == 2) now = a[i];
		}
		memset(used, 0, sizeof(used)); used[now] = 1;
		tmp[len2 = 1] = now; len3 = 0;
		while (1) {
			int nowlen = min(len2, n - len2);
			cout << "? " << nowlen << " " << nowlen << endl;
			for (int i = 1, cnt = 0; i <= n; i++) {
				if (!used[i]) {
					++cnt;
					cout << i << " ";
					res[++len3] = i;
					if (cnt == nowlen) break;
				}
			}
			cout << endl;
			for (int i = 1; i <= nowlen; i++) cout << tmp[i] << " ";
			cout << endl;
			int ans = query();
			if (ans == 2) {
				break;
			}
			for (int i = 1; i <= len3; i++) {
				used[res[i]] = 1;
				tmp[++len2] = res[i];
			}
			len3 = 0;
		}
		int l = 1, r = len3 - 1, ans = len3;
		while (l <= r) {
			int mid = (l + r) >> 1;
			cout << "? " << mid << " " << mid << endl;
			for (int i = 1; i <= mid; i++) cout << res[i] << " ";
			cout << endl;
			for (int i = 1; i <= mid; i++) cout << tmp[i] << " ";
			cout << endl;
			int nowans = query();
			if (nowans == 2) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << "! " << res[ans] << endl;
	}
    return 0;
}