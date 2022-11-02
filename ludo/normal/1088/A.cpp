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

	int x;
	cin >> x;

	// a = b*k
	// a/b = k < x
	// k b^2 > x
	// b k <= x
	for (int a = 1; a <= x; a++) for (int b = 1; b <= x; b++) {
		if (a % b != 0) continue;
		if (a * b <= x) continue;
		if (a / b >= x) continue;
		cout << a << " " << b << endl;
		return 0;
	}
	cout << "-1" << endl;

	return 0;
}