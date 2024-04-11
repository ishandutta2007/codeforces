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

	int n; cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; ++i){
		bool ok = true;
		for (int j = 0; j < n; ++j){
			int v; cin >> v;
			if (v == 1 || v == 3) ok = false;
		}
		if (ok) ans.push_back(i + 1);
	}

	cout << ans.size() << endl;
	for (auto car : ans) cout << car << " ";
	cout << endl;


	return 0;
}