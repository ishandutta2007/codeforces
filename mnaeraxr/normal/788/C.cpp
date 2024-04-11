#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

int solve(int n, int k, vector<bool> &ok){
	if (ok[ n ])
		return 1;

	int answer = -1;

	for (int a = n + 1; a <= 1000; ++a){
		if (!ok[a]) continue;

		for (int b = 0; b < n; ++b){
			if (!ok[b]) continue;

			int A = a - n, B = n - b;
			int G = __gcd(A, B);

			int cur = B / G + A / G;

			if (answer == -1 || cur < answer)
				answer = cur;
		}
	}

	return answer;
}

const int maxn = 100000;
const int center = maxn / 2;

int dp[ maxn ];

int good(int n, int k, vector<bool> &ok){
	memset(dp, oo, sizeof dp);

	for (int i = 0; i <= 1000; ++i){
		if (!ok[i]) continue;
		int v = i - n + center;
		dp[ v ] = 1;
	}

	for (int i = 0; i <= 1000; ++i){
		int t = i - n;

		if (!ok[i]) continue;

		if (t > 0){
			for (int j = 0; j + t < maxn; ++j)
				dp[j + t] = min( dp[j + t], dp[j] + 1 );
		}
		else if (t < 0){
			for (int j = maxn - 1; j + t >= 0; --j)
				dp[j + t] = min( dp[j + t], dp[j] + 1 );
		}
	}

	if (dp[ center ] == oo) dp[ center ] = -1;

	return dp[ center ];
}

void tester(){
	int t = 1000;

	int MX = 210;

	srand(2);

	while (t--){
		int n = rand() % MX;
		int k = 10;

		vector<bool> ok(1001);

		cout << "n:: " << n << endl;

		for (int i = 0; i < k; ++i){
			int v = rand() % MX;
			ok[ v ] = true;
		}

		for (int j = 0; j <= MX; ++j)
			if (ok[j]) cout << j - n << " ";
		cout << endl;

		int A = good(n, k, ok), B = solve(n, k, ok);
		cout << "here: " << A << " " << B << endl;
		if (A != B){
			cout << "~~~~~~~~~~~~~~~~~" << endl;
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<bool> ok(1001);

	for (int i = 0; i < k; ++i){
		int v; cin >> v;
		ok[ v ] = 1;
	}

	int A = good(n, k, ok);
	int B = solve(n, k, ok);

	if (A == -1) A = B;

	cout << A << endl;

	return 0;
}