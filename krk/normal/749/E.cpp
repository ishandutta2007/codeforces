#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
ld res;

void Solve(vector <int> &V, ll &sum, ll &sqsum)
{
	sum = 0; sqsum = 0;
	if (V.size() == 0) return;
	if (V.size() == 1) { sum = V.back(); sqsum = ll(V.back()) * V.back(); return; }
	int m = V.size() / 2;
	vector <int> A, B;
	for (int i = 0; i < m; i++)
		A.push_back(V[i]);
	for (int i = m; i < V.size(); i++)
		B.push_back(V[i]);
	ll asum, asqsum, bsum, bsqsum;
	Solve(A, asum, asqsum); Solve(B, bsum, bsqsum);
	sum = asum + bsum; sqsum = asqsum + bsqsum;
	int l = 0, r = 0;
	V.clear();
	while (l < A.size() && r < B.size())
		if (a[A[l]] < a[B[r]]) { V.push_back(A[l]); asum -= A[l]; asqsum -= ll(A[l]) * A[l]; l++; } 
		else {
			res += (ld(ll(n) * (n - 1) + 2 * B[r]) * ld(A.size() - l) + ld(asum) * ld(2 * B[r] - 2 * n)) / (ld(n) * (n + 1));
			V.push_back(B[r++]);
		}
	while (l < A.size()) V.push_back(A[l++]);
	while (r < B.size()) V.push_back(B[r++]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	res = 0;
	for (int i = 1; i <= n; i++)
		res += ld(n - i + 1) * i * (i - 1) / (ld(n) * (n + 1));
	res /= 2.0l;
	vector <int> V;
	for (int i = 0; i < n; i++)
		V.push_back(i);
	ll sum, sqsum;
	Solve(V, sum, sqsum);
	cout << fixed << setprecision(15) << res << endl;
	return 0;
}