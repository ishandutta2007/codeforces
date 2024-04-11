#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1000;
int cur[N];

void makeOp(int n, vector<int>& op) {
	int k = op.size();
	cout << k << endl;
	for (auto i : op) {
		cout << i+1 << ' ';
		cur[i] = 1;
	}
	cout << endl;

	int a;
	cin >> a;
	--a;
	for (int i = a; i < a+k; ++i) {
		cur[i % n] = 0;
	}
}

void finish() {
	cout << 0 << endl;
}

// Max count with static target with max streak length k
int getOff(int n, int k) {
	int zero = (n + k) / (k+1);
	return n - zero - k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Assume first a static target: at every step, A turns on every spot that is on in their target
	// If we head towards a static target, with longest streak k, we can get within k of it
	//	-> We can get n * k/(k+1) - k = (n/(k+1) - 1) * k
	//	-> Maximised at (k+1)^2 = n
	//	-> For n = m^2, maximum amount is (m-1)^2

	// When n = m^2, (m-1)^2 is a clear upper bound
	//	Strategy for B: when A turns on lamps, find position with longest streak, and start your delete there
	//		We don't even care if we delete any more than just the streak!
	//		After A's last move, before B's, let longest streak be k.
	//		Then there are at most n * k/(k+1)
	//		But WLOG last move pair incremented on count, so B can delete that streak entirely
	//		-> At most n * k/(k+1) - k
	//		-> R(n) = max_k(n * k/(k+1) - k)

	int n;
	cin >> n;

	int tar = 0;
	int k = 0;
	for (int tk = 1; tk < n; ++tk) {
		int off = getOff(n, tk);
		if (off > tar) {
			tar = off;
			k = tk;
		}
	}
	int m = k+1;

	while(true) {
		int cou = 0;
		for (int i = 0; i < n; ++i) {
			if (cur[i]) ++cou;
		}
		if (cou >= tar) break;

		vector<int> op;
		for (int i = 0; i < n; ++i) {
			if ((i % m != 0) && (cur[i] == 0)) op.push_back(i);
		}
		makeOp(n, op);
	}
	finish();
}