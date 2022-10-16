#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 5000 + 10;

int sg(int a){
	if (a == 0) return 0;
	return a < 0 ? -1 : 1;
}

int over(int A, int B, int O, int idx, int jdx){
	pii x(A, -idx), y(B, -idx), z(O, -jdx);
	if (y < x) swap(x, y);
	return x < z && z < y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> A(n), B(n), I(n);

	for (int i = 0; i < n; ++i) cin >> A[i] >> B[i];
	for (int i = 0; i < n; ++i) I[i] = i;

	auto cmp = [&](int x, int y){
		int sx = sg(B[x]), sy = sg(B[y]);
		if (sx != sy) return sx < sy;
		if (A[x] != A[y]) return sx * A[x] < sy * A[y];

		if (sx == 1) return x > y;
		return y > x;
	};

	sort(I.begin(), I.end(), cmp);

	int answer = 0;

	for (int i = 0; i < n; ++i){
		int u = I[i];

		for (int j = 0; j < n; ++j){
			if (u == j) continue;
			if (over(A[u], A[u] + B[u], A[j], u, j))
				answer++;
		}

		A[u] += B[u];
	}

	cout << answer << endl;

	return 0;
}