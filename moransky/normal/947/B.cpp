// xtqqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, v[N], T[N];

LL d;

priority_queue<LL, vector<LL>, greater<LL> > q;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(v[i]);
	for (int i = 1; i <= n; i++) read(T[i]);
	for (int i = 1; i <= n; i++) {
		q.push(v[i] + d);
		LL res = 0;
		while (q.size() && q.top() - d < T[i]) {
			LL u = q.top() - d; 
			res += u;
			q.pop();
		}
		res += (LL)q.size() * T[i];
		printf("%lld ", res);
		d += T[i];
	}
    return 0;
}