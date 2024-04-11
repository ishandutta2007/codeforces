#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define rs resize
#define all(v) (v).begin(), (v).end()

void run() {
	int N, K;
	cin >> N >> K;

	cout << "YES" << endl;
	for (int i = 0; i < N; i++) cout << "."; cout << endl;
	if (K % 2 == 0) {
		// symmetric over mirroring rows
		int m = K / 2;
		cout << "."; for (int i = 1; i <= m; i++) cout << "#"; for (int i = m + 1; i < N; i++) cout << "."; cout << endl;
		cout << "."; for (int i = 1; i <= m; i++) cout << "#"; for (int i = m + 1; i < N; i++) cout << "."; cout << endl;
	} else {
		// K - 1 == 2 M
		int half = (K - 1) / 2;
		int ntop = min(half, (N - 3) / 2);
		int nbot = 1 + half - ntop;

		for (int i = 0; i < N; i++) {
			bool hash = abs(i - (N - 1) / 2) <= ntop;
			cout << (hash ? '#' : '.');
		}
		cout << endl;

		for (int i = 0; i < N; i++) {
			bool hash = abs(i - (N - 1) / 2) < nbot;
			hash &= i != (N - 1) / 2;
			cout << (hash ? '#' : '.');
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) cout << "."; cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	run();

	return 0;
}