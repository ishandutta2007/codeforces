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

const int maxn = 1e3;
int N, a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	int ret = 0;
	for (int i = 1; i + 1 < N; i++) {
		if ((a[i - 1] < a[i] && a[i + 1] < a[i]) || (a[i - 1] > a[i] && a[i + 1] > a[i])) ret++;
	}
	cout << ret << endl;

	return 0;
}