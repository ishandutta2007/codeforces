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

vi idxs[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	cin >> S;
	int N = S.size();

//	for (int i = 0; i < 26; i++)
//		idxs[i].pb(-1);

	for (int i = 0; i < N; i++) {
		idxs[S[i] - 'a'].pb(i);
	}

	for (int i = 0; i < 26; i++)
		idxs[i].pb(N);

	int retK = 1e7;
	for (int i = 0; i < 26; i++) {
		if (idxs[i].empty()) continue;

		int lastVal = -1, altK = -1;
		for (int val : idxs[i]) {
			altK = max(altK, val - lastVal);
			lastVal = val;
		}
		retK = min(retK, altK);
	}
	cout << retK << endl;
	return 0;
}