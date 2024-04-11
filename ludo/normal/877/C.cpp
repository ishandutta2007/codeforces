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
	int N;
	cin >> N;
	/*
	if (N == 2) {
		cout << "3\n2 1 2\n"; return;
	} else if (N == 3){
		cout << "4\n2 1 3 2\n"; return;
	}
	cout << (2 * N - 2) << endl;
	cout << "2 1";
	for (int i = 3; i <= N; i++) cout << " " << i;
	for (int i = 2; i < N; i++) cout << " " << i;
	cout << endl;
	*/
	int k = N / 2;
	cout << (3 * N / 2) << endl;
	// if (N % 2 == 0) {
		// cout << (3 * k) << endl;
		cout << (N - 1);
		for (int i = N - 3; i > 0; i -= 2) cout << " " << i;
		for (int i = N; i > 0; i -= 2) cout << " " << i;
		for (int i = N - 1; i > 0; i -= 2) cout << " " << i;
		cout << endl;
	/*
	} else {
		// cout << (3 * k + 1) << endl;
		cout << (N - 1);
		for (int i = N - 3; i > 0; i -= 2) cout << " " << i;
		for (int i = N; i > 0; i -= 2) cout << " " << i;
		for (int i = N - 1; i > 0; i -= 2) cout << " " << i;
		cout << endl;
	}
	*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	run();

	return 0;
}