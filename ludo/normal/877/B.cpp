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

const int maxn = 5005;

string S;
int N, cnta[maxn], cntb[maxn];

void run() {
	cin >> S;
	N = S.size();
	cnta[0] = cntb[0] = 0;
	for (int i = 1; i <= N; i++) {
		cnta[i] = cnta[i - 1] + (S[i - 1] == 'a');
		cntb[i] = cntb[i - 1] + (S[i - 1] == 'b');
	}

	int ans = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			// part 1: [0, i)
			// part 2: [i, j)
			// part 3: [j, N)
			int len1 = cnta[i];
			int len2 = cntb[j] - cntb[i];
			int len3 = cnta[N] - cnta[j];
			ans = max(ans, len1 + len2 + len3);
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	run();

	return 0;
}