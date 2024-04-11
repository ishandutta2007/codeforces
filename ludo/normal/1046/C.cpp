#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int maxn = 2e5 + 10;
int N, D, A[maxn], B[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> D;
	REP(i, N) cin >> A[i];
	REP(i, N) cin >> B[i];

	D--;

	A[D] += B[0];
	int ret = D;
	for (int i = D - 1, j = 1; i >= 0; i--) {
		while (j < N && A[i] + B[j] > A[D])
			j++;
		if (j == N) break;
		// cerr << "For " << i << ", take " << B[j] << endl;
		A[i] += B[j++];
		ret = i;
	}

	// other teams behind A[D], will have a lower begin rating, and we will assign it a lower increase.
	// other teams before A[D] cannot be overtaken.

	// REP(i, N) cerr << A[i] << " ";
	cout << (ret + 1) << endl;
	return 0;
}