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

const int N = 2e5 + 5;

int n, a[N];

int main() {
    int T; read(T);
    while (T--) {
    	read(n);
    	for (int i = 1; i <= n; i++) read(a[i]);
    	bool o = 0;
    	for (int i = 1; i < n; i++)
    		if (a[i] == a[i + 1]) o = 1;
    	if (!o) puts("0");
    	else {
    		int A = -1, B = -1;
    		for (int i = 1; i < n; i++) {
    			if (a[i] == a[i + 1]) {
    				if (A == -1) A = i;
    				B = i;
    			}
    		}
    		if (A == B) puts("0");
    		else {
    			printf("%d\n", max(B - A - 1, 1));
    		}
    	}
    }
    return 0;
}