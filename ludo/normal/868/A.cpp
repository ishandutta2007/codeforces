#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define all(v) (v).begin(), (v).end()

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void run()
{
	string A;
	int n;
	cin >> A >> n;
	vector<bool> fl(256, false), ll(256, false);
	bool can = false;
	for (int i = 0; i < n; i++) {
		string S;
		cin >> S;
		can |= A == S;
		fl[S[0]] = ll[S[1]] = true;
	}
	can |= (fl[A[1]] && ll[A[0]]);
	cout << (can ? "YES" : "NO") << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	(cout << fixed).precision(18);

	run();

	return 0;
}