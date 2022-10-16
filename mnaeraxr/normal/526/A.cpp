#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
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

	int n; cin >> n;
	string s;
	cin >> s;
	bool ok = false;
	for (int i = 1; i < n && !ok; ++i){
		for (int j = 0; j + 4 * i < n && !ok; ++j)
		{
			int cnt = 0;
			for (int k = 0; k < 5; ++k)
				cnt += s[j + i * k] == '*';
			if (cnt == 5) ok = true;
		}
	}
	if (ok) cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}