#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n, q;
vector <int> V;
set <ll> S;

void Solve(const vector <int> &V)
{
	ll sum = 0;
	vector <int> L, R;
	int mid = (V[0] + V.back()) / 2;
	for (int i = 0; i < V.size(); i++) {
		sum += V[i];
		if (V[i] <= mid) L.push_back(V[i]);
		else R.push_back(V[i]);
	}
	S.insert(sum);
	if (L.empty() || R.empty()) return;
	Solve(L);
	Solve(R);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &q);
		V.clear();
		S.clear();
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			V.push_back(a);
		}
		sort(V.begin(), V.end());
		Solve(V);
		while (q--) {
			ll a; scanf("%I64d", &a);
			printf("%s\n", S.find(a) != S.end()? "Yes": "No");
		}
	}
    return 0;
}