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

	int W, H;
	cin >> H >> W;
	string S; getline(cin, S);
	int t = 1000, b = -1000, l = 1000, r = -1;
	for (int i = 1; i <= H; i++) {
		getline(cin, S);
		for (int j = 1; j <= W; j++) {
			if (S[j - 1] == 'B') {
				t = min(t, i); b = max(b, i);
				l = min(l, j); r = max(r, j);
			}
		}
	}

	int ah = t + b;
	int aw = l + r;

	cout << (ah / 2) << " " << (aw / 2) << endl;
	return 0;
}