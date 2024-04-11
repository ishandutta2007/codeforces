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
	int64 ans = 1;
	for (int i = 0; i < SZ(s); ++i){
		ans <<= 1;
		if (s[i] == '7') ans ^= 1;
	}
	ans -= 1;
	cout << ans << endl;

	return 0;
}