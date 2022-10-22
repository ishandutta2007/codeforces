#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef pair <ld, ii> ldii;

const int Maxn = 2005;

int n;
ll s;
int X[Maxn], Y[Maxn];
int srt[Maxn];
int inplace[Maxn];
vector <ldii> V; 

bool Less(const int &a, const int &b)
{
	if (Y[a] != Y[b]) return Y[a] < Y[b];
	return X[a] > X[b];
}

void Swap(int a, int b)
{
	int i = inplace[a], j = inplace[b];
	swap(srt[i], srt[j]);
	inplace[srt[i]] = i; inplace[srt[j]] = j;
}

ll Cross(int a, int b, int c)
{
	int ax = X[c] - X[a], ay = Y[c] - Y[a];
	int bx = X[b] - X[a], by = Y[b] - Y[a];
	return ll(ax) * by - ll(ay) * bx;
}

int main()
{
	scanf("%d %I64d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		srt[i] = i;
	}
	sort(srt, srt + n, Less);
	for (int i = 0; i < n; i++)
		inplace[srt[i]] = i;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j)
			V.push_back(ldii(atan2(ld(Y[j] - Y[i]), ld(X[j] - X[i])), ii(i, j)));
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		int a = V[i].second.first, b = V[i].second.second;
		int lef = 0, rig = n - 1;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			ll got = Cross(a, b, srt[mid]);
			if (got < 2 * s) lef = mid + 1;
			else if (got > 2 * s) rig = mid - 1;
			else {
				printf("Yes\n");
				printf("%d %d\n", X[a], Y[a]);
				printf("%d %d\n", X[b], Y[b]);
				printf("%d %d\n", X[srt[mid]], Y[srt[mid]]);
				return 0;
			}
		}
		Swap(a, b);
	}
	printf("No\n");
	return 0;
}