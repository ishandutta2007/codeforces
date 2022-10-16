#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long int64;

vector<int> pos[26];
vector<int> T;
int ptr[26];

int64 solve(vector<int> &V, int b, int e)
{
	if (b == e) return 0;
	int mid = (b + e) >> 1;
	int64 ans = solve(V, b, mid) + solve(V, mid + 1, e);
	int p1 = b, p2 = mid + 1;
	int cnt = b;
	while (p1 <= mid && p2 <= e)
	{
		if (V[p1] < V[p2]) T[cnt++] = V[p1++];
		else T[cnt++] = V[p2++], ans += mid + 1 - p1;
	}
	while (p1 <= mid) T[cnt++] = V[p1++];
	while (p2 <= e) T[cnt++] = V[p2++];
	for (int i = b; i <= e; ++i) V[i] = T[i];

	return ans;
}

vector<int> reverse(vector<int> v, int x, int y)
{
	vector<int> ans = v;
	for (int i = 0; i <= (y - x) / 2; ++i){
		swap(ans[x + i], ans[y - i]);
	}
	return ans;
}

int64 bt(vector<int> L, int k)
{
	if (k == 0)
	{
		T = vector<int>(L.size());
		return solve(L, 0, L.size() - 1);
	}
	int64 ans = 0;
	for (int i = 0; i < L.size(); ++i)
		for (int j = i; j < L.size(); ++j)
			ans += bt( reverse(L, i, j), k - 1);
	return ans;
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> B(n);
 	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	int64 s = bt(B, k);

//	cout << s << endl;
	int64 value = n * (n + 1) / 2;
	int64 den = value;
	for (int i = 1; i < k; ++i) den *= value;
//	cout << den << endl;
	double ans = 1.0  * s / den;

	cout.precision(11);
	cout << fixed << ans << endl;

	return 0;
}