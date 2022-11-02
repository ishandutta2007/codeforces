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

	string A[6];
	REP(i, 6) cin >> A[i];

	bool ans = false;
	REP(i, 5) ans |= A[0][0] == A[i+1][0] || A[0][1] == A[i+1][1];
	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}