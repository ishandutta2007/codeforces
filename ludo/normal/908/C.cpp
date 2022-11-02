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

const int maxn = 1000;

ll N, R, x[maxn];
ld h[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	(cout << fixed).precision(18);
	cout.tie(NULL);

	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		h[i] = R;
		for (int j = 0; j < i; j++) {
			ll dx = abs(x[i] - x[j]);
			if (dx <= 2 * R) {
				ld alt = h[j] + sqrt(((ld) 4.0) * R * R - ((ld) dx) * dx);
				h[i] = max(h[i], alt);
			}
		}
		cout << h[i] << " \n"[i == N - 1];
	}
	return 0;
}