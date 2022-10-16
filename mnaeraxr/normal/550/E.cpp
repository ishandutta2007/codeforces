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
	vector<int> V(n);

	int tot = 0;

	for (int i = 0; i < n; ++i){
		cin >> V[i];
		if (!V[i]) ++tot;
	}

	if (n == 1){
		if (V[0] == 0) cout << "YES\n0\n";
		else cout << "NO" << endl;
		exit(0);
	}

	if (V[n - 1] == 1 || (V[n - 2] == 0 && tot == 2)){
		cout << "NO" << endl;
		exit(0);
	}

	cout << "YES" << endl;
	for (int i = 0; i < n - 2; ++i)	cout << "(" << V[i] << "->";
	cout << V[n - 2];
	for (int i = 0; i < n - 2; ++i) cout << ")";
	cout << "->0" << endl;

	return 0;
}