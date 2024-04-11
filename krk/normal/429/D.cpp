#include <cstdio>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int n;
int X[Maxn], Y[Maxn];
set <ii> S;
ll res = Inf;
int cur = 1001000000;

ll getDist(int a, int b)
{
	return ll(X[a] - X[b]) * (X[a] - X[b]) + ll(Y[a] - Y[b]) * (Y[a] - Y[b]);
}

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		X[i] = i;
		int a; scanf("%d", &a);
		sum += a;
		Y[i] = sum;
	}
	int l = 0;
	for (int i = 0; i < n; i++) {
		while (l < i && X[i] - X[l] > cur) { S.erase(ii(Y[l], l)); l++; }
		set <ii>::iterator it1 = S.lower_bound(ii(Y[i] - cur, 0));
		set <ii>::iterator it2 = S.upper_bound(ii(Y[i] + cur, n));
		for (set <ii>::iterator it = it1; it != it2; it++) {
			ll d = getDist(i, it->second);
			if (d < res) { res = d; cur = int(sqrt(ld(d)) + 0.5); }
		}
		S.insert(ii(Y[i], i));
	}
	printf("%I64d\n", res);
	return 0;
}