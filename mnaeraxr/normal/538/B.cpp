#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int m = 0;

	for (int i = 0; i < (int)s.length(); ++i){
		m = max(s[i] - '0', m);
	}

	cout << m << endl;
	for (int i = 0; i < m; ++i){
		int cur = 0;
		for (int j = 0; j < (int)s.length(); ++j){
			cur *= 10;
			if (s[j] - '0' > 0){
				cur++;
				s[j]--;
			}
		}
		cout << cur << " ";
	}
	cout << endl;

	return 0;
}