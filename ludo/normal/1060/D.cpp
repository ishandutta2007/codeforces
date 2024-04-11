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

const int maxn = 1e5;
int N, L[maxn], R[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	REP(i, N) cin >> L[i] >> R[i];

	sort(L, L + N);
	sort(R, R + N);

	ll ret = N; // everybody needs one seat.
	while (N--) {
		ret += max(L[N], R[N]);
	}
	cout << ret << endl;
	return 0;
}