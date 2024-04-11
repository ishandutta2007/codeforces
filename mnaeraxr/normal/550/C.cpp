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

	string s; cin >> s;

	s = "00" + s;

	for (int j1 = 0; j1 < SZ(s); ++j1){
		for (int j2 = j1 + 1; j2 < SZ(s); ++j2){
			for (int j3 = j2 + 1; j3 < SZ(s); ++j3){
				int cur = (s[j1] - '0') * 100 + (s[j2] - '0') * 10 + (s[j3] - '0');
				if (cur % 8 == 0){
					cout << "YES" << endl;
					cout << cur << endl;
					exit(0);
				}
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}