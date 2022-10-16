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

	string s; int k;
	cin >> s >> k;
	bool ok = true;
	int len = (int)s.length() / k;

	if (k * len != (int)s.length()){
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < k && ok; ++i){
		int b = i * len, e = b + len - 1;
		while (b < e){
			if (s[b] != s[e]){
				ok = false;
				break;
			}
			else{
				++b; --e;
			}
		}
	}

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}