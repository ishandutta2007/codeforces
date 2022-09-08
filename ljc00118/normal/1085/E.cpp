#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 3e6 + 5;

char a[N], b[N], c[N];
int pre[26], qwq[26], used[26], qwq2[26], ppre[26];
int T, n, k, ans;

void calc1(int now) {
	memcpy(qwq, pre, sizeof(qwq));
	memcpy(qwq2, used, sizeof(qwq2));
	int res = 1;
	for(register int i = now; i <= n; i++) {
		if(~pre[c[i] - 'a']) {
			char now = pre[c[i] - 'a'] + 'a';
			if(now > b[i]) { res = 0; break; }
			if(now < b[i]) {
				ans = 1; return;
			}
		} else {
			for(register int j = b[i] - 'a' - 1; j >= 0; j--) {
				if(used[j] == 0) {
					used[j] = 1;
					pre[c[i] - 'a'] = j;
					ans = 1; return;
				}
			}
			if(used[b[i] - 'a'] != 0) { res = 0; break; }
			used[b[i] - 'a'] = 1; pre[c[i] - 'a'] = b[i] - 'a';
		}
	}
	if(res == 1) { ans = 1; return; }
	memcpy(pre, qwq, sizeof(pre));
	memcpy(used, qwq2, sizeof(used));
}

void calc2(int now) {
	memcpy(qwq, pre, sizeof(qwq));
	memcpy(qwq2, used, sizeof(qwq2));
	int res = 1;
	for(register int i = now; i <= n; i++) {
		if(~pre[c[i] - 'a']) {
			char now = pre[c[i] - 'a'] + 'a';
			if(now < a[i]) { res = 0; break; }
			if(now > a[i]) {
				ans = 1; return;
			}
		} else {
			for(register int j = a[i] - 'a' + 1; j < k; j++) {
				if(used[j] == 0) {
					used[j] = 1;
					pre[c[i] - 'a'] = j;
					ans = 1; return;
				}
			}
			if(used[a[i] - 'a'] != 0) { res = 0; break; }
			used[a[i] - 'a'] = 1; pre[c[i] - 'a'] = a[i] - 'a';
		}
	}
	if(res == 1) { ans = 1; return; }
	memcpy(pre, qwq, sizeof(pre));
	memcpy(used, qwq2, sizeof(used));
}

int main() {
	read(T); while(T--) {
		memset(pre, -1, sizeof(pre));
		memset(used, 0, sizeof(used));
		read(k); scanf("%s%s%s", c + 1, a + 1, b + 1);
		n = strlen(a + 1); ans = 0;
		for(register int i = 1; i <= n; i++) {
//			fprintf(stderr, "i = %d\n", i);
			if(~pre[c[i] - 'a']) {
				char now = pre[c[i] - 'a'] + 'a';
				if(now < a[i] || now > b[i]) break;
				if(now > a[i] && now < b[i]) {
					ans = 1;
					break;
				}
				if(a[i] != b[i]) {
					if(now == a[i]) calc2(i + 1); if(ans) break;
					if(now == b[i]) calc1(i + 1); if(ans) break;
					break;
				}
			} else {
				for(register int j = a[i] - 'a' + 1; j <= b[i] - 'a' - 1; j++) {
					if(used[j] == 0) {
						used[j] = 1;
						pre[c[i] - 'a'] = j;
						ans = 1; break;
					}
				}
				if(ans) break;
				if(a[i] == b[i]) {
					if(used[a[i] - 'a'] != 0) break;
					used[a[i] - 'a'] = 1; pre[c[i] - 'a'] = a[i] - 'a';
				} else {
					if(used[a[i] - 'a'] == 0) {
						used[a[i] - 'a'] = 1; pre[c[i] - 'a'] = a[i] - 'a';
						calc2(i + 1); if(ans) break;
						used[a[i] - 'a'] = 0; pre[c[i] - 'a'] = -1;
					}
					if(used[b[i] - 'a'] == 0) {
						used[b[i] - 'a'] = 1; pre[c[i] - 'a'] = b[i] - 'a';
						calc1(i + 1); if(ans) break;
						used[b[i] - 'a'] = 0; pre[c[i] - 'a'] = -1;
					}
					break;
				}
			}
			if(i == n) ans = 1;
		}
		if(ans == 0) printf("NO\n");
		else {
//			for(register int i = 0; i < k; i++) print(used[i], i == (k - 1) ? '\n' : ' ');
			printf("YES\n"); int now = 0;
			for(register int i = 0; i < k; i++) {
				if(pre[i] == -1) {
					for(; ; now++) if(used[now] == 0) break;
					putchar(now + 'a'); now++;
				} else putchar(pre[i] + 'a');
			}
			putchar('\n');
		}
	}
	return 0;
}