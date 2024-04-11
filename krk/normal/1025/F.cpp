#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;
typedef long long ll;
typedef pair <ld, ii> ldii;

const int Maxn = 2005;

int n;
int X[Maxn], Y[Maxn];
vector <ldii> V;
int seq[Maxn];
int my[Maxn];
ll res;

bool Less(const int &a, const int &b)
{
	if (Y[a] != Y[b]) return Y[a] < Y[b];
	return X[a] > X[b];
}

void Swap(int a, int b)
{
	int i = my[a], j = my[b];
	swap(seq[i], seq[j]);
	my[seq[i]] = i; my[seq[j]] = j;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		seq[i] = i;
	}
	sort(seq, seq + n, Less);
	for (int i = 0; i < n; i++)
		my[seq[i]] = i;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j)
			V.push_back(ldii(atan2(ld(Y[j] - Y[i]), ld(X[j] - X[i])), ii(i, j)));
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		int a = V[i].second.first, b = V[i].second.second;
		int lef = 0, rig = n - 1;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			ll ax = X[b] - X[a], ay = Y[b] - Y[a];
			ll bx = X[seq[mid]] - X[a], by = Y[seq[mid]] - Y[a];
			if (ax * by - ay * bx > 0) lef = mid + 1;
			else rig = mid - 1;
		}
		rig = n - 2 - lef;
		res += (ll(lef) * (lef - 1) / 2) * (ll(rig) * (rig - 1) / 2);
		Swap(a, b);
	} 
	res /= 2;
	printf("%I64d\n", res);
	return 0;
}