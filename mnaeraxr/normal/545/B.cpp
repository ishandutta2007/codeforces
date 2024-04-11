#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s, t; cin >> s >> t;
	string p = s;

	int tot = 0;
	for (int i = 0; i < SZ(s); ++i){
		if (s[i] != t[i]){
			if (tot & 1) p[i] = s[i];
			else p[i] = t[i];
			++tot;
		}
	}

	if (tot & 1) cout << "impossible" << endl;
	else cout << p << endl;

	return 0;
}