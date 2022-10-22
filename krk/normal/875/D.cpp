#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxb = 31;
const int Maxn = 200005;

int n;
int a[Maxn];
int L[Maxn][Maxb], R[Maxn][Maxb];
vector <ii> seq;
set <int> S;
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < Maxb; j++)
			L[i][j] = (a[i] & 1 << j)? i: L[i - 1][j];
	}
	for (int j = 0; j < Maxb; j++)
		R[n + 1][j] = n + 1;
	for (int i = n; i >= 1; i--)
		for (int j = 0; j < Maxb; j++)
			R[i][j] = (a[i] & 1 << j)? i: R[i + 1][j];
	S.insert(0); S.insert(n + 1);
	for (int i = 1; i <= n; i++)
		seq.push_back(ii(a[i], i));
	sort(seq.rbegin(), seq.rend());
	for (int i = 0; i < seq.size(); i++) {
		int ind = seq[i].second;
		set <int>::iterator it = S.upper_bound(ind);
		int myR = *it - 1;
		it--; int myL = *it + 1;
		S.insert(ind);
		int A = myL - 1, B = myR + 1;
		for (int j = 0; j < Maxb; j++)
			if (!(a[ind] & 1 << j)) {
				A = max(A, L[ind][j]);
				B = min(B, R[ind][j]);
			}
		res += ll(A - myL + 1) * (myR - ind + 1) + ll(ind - myL + 1) * (myR - B + 1) - ll(A - myL + 1) * (myR - B + 1);
	}
	printf("%I64d\n", res);
	return 0;
}