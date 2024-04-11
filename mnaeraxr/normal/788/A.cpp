#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i){
		cin >> v[i];
		if (i) v[i - 1] = abs(v[i] - v[i - 1]);
	}

	int64 answer = 0, suff = 0;

	for (int i = 0; i + 1 < n; ++i){
		int64 cur = i & 1 ? -v[i] : v[i];
		suff = max(cur, suff + cur);
		answer = max(answer, suff);
	}

	suff = 0;

	for (int i = 1; i + 1 < n; ++i){
		int64 cur = i & 1 ? v[i] : -v[i];
		suff = max(cur, suff + cur);
		answer = max(answer, suff);
	}

	cout << answer << endl;

	return 0;
}