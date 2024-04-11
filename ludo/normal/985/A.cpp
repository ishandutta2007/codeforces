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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vi A(N/2);
	REP(i, N / 2) cin >> A[i];
	sort(all(A));

	int a1 = 0, a2 = 0;
	for (int i = 1; i <= N; i += 2) {
		int x = A[i / 2];
		// cerr << "DIFF: " << abs(x - i) << " " << abs(x - i - 1) << endl;
		a1 += abs(x - i);
		a2 += abs(x - (i + 1));
	}

//	cerr << a1 << " " << a2 << endl;
	cout << min(a1, a2) << endl;

	return 0;
}