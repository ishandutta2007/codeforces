#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

	int n;
	cin >> n;
	vi A(n);
	ll totc = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		totc += ll(b) * (n-1);
		A[i] = a - b;
	}
	sort(all(A));
	reverse(all(A));
	for (int i = 0; i < n; i++) {
		totc += ll(i) * A[i];
	}
	cout << totc << endl;

	return 0;
}