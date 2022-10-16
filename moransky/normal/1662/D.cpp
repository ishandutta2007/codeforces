// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 205;

bool f[N][N];

char a[N], b[N];

int n, m;

int A[3], B[3];

int main() {
    int T; read(T);
    while (T--) {
    	scanf("%s%s", a + 1, b + 1);
    	memset(f, 0, sizeof f);
    	n = strlen(a + 1);
    	m = strlen(b + 1);
    	memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        string sa = "", sb = "";
    	for (int i = 1; i <= n; i++) {
    		A[a[i] - 'A'] ^= 1;
    		char v = a[i];
    		if (v == 'A' || v == 'C') {
    			if (sa.size() && sa.back() == v) sa.pop_back();
    			else sa += v;
    		}
    	}
    	for (int i = 1; i <= m; i++) {
    		B[b[i] - 'A'] ^= 1;
    		char v = b[i];
    		if (v == 'A' || v == 'C') {
    			if (sb.size() && sb.back() == v) sb.pop_back();
    			else sb += v;
    		}
    	}
    	bool o = 1;
    	for (int i = 0; i < 3; i++) if (A[i] != B[i]) o = 0;
    	if (sa != sb) o = 0;
    	puts(o ? "YES" : "NO");
    }
    return 0;
}