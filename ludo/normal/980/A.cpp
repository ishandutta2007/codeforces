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
	string S;
	cin >> S;
	int N = S.size();
	int M = 0;
	for (char ch : S) {
		M += ch == '-';
	}
	int K = N - M;

	cerr << "HEY: " << M << " " << K << endl;
	bool can = K == 0 || M % K == 0;
	cout << (can ? "YES" : "NO") << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	run();

	return 0;
}