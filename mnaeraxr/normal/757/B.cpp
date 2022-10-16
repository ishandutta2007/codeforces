#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int FFF[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n; cin >> n;

	int M = 0;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		FFF[v]++;

		M = max(M, v);
	}

	int answer = 1;

	for (int i = 2; i <= M; ++i){
		int cur = 0;

		for (int j = i; j <= M; j += i)
			cur += FFF[j];

		answer = max(answer, cur);
	}

	cout << answer << endl;

	return 0;
}