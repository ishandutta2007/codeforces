#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 10005;

int n, w, v, u;
int X[Maxn], Y[Maxn];

ll Cross(ll ax, ll ay, ll bx, ll by) { return ax * by - ay * bx; }

int main()
{
	scanf("%d %d %d %d", &n, &w, &v, &u);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &X[i], &Y[i]);
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		ll cr = Cross(v, u, X[i], Y[i]);
		if (cr < 0) a++;
		else if (cr > 0) b++;
	}
	if (a == 0 || b == 0) cout << fixed << setprecision(12) << ld(w) / ld(u);
	else {
		for (int i = 0; i < n; i++) {
			ll cr1 = Cross(v, u, X[i], Y[i]);
			ll cr2 = Cross(v, u, X[(i + 1) % n], Y[(i + 1) % n]);
			if (cr1 > 0 && cr2 <= 0) {
				int nxt = (i + 1) % n;
				while (Cross(v, u, X[(nxt + 1) % n] - X[nxt], Y[(nxt + 1) % n] - Y[nxt]) < 0)
					nxt = (nxt + 1) % n;
				ld lft = w - Y[nxt];
				ld res = ld(X[nxt]) / v + lft / u;
				cout << fixed << setprecision(12) << res << endl;
				break;
			}
		}
	}
	return 0;
}