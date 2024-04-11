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
	string S;
	cin >> n >> S;

	int cnt[26];
	for (int i = 0; i < n; i++) {
		fill_n(cnt, 26, 0);
		for (int j = i + 1; j <= n; j++) {
			int idx = S[j - 1] - 'a';
			cnt[idx]++;

			bool val = true;
			REP(k, 26) val &= 2 * cnt[k] <= (j - i);

			if (val) {
				cerr << i << " " << j << endl;
				printf("YES\n%s\n", S.substr(i, j - i).c_str());
				return 0;
			}
		}
	}
	printf("NO\n");

	return 0;
}