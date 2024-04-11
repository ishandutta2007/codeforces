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

void print(int n, int k){
	for (int i = 1; i < k; ++i){
		cout << n << " " << n + i << endl;
		if (i % 2 == 0)
			cout << n + k + i - 2 << " " << n + k + i - 1 << endl;

		for (int j = 1; j < k; ++j){
			cout << n + i << " " << n + k + j - 1 << endl;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	if (n % 2 == 0){
		cout << "NO" << endl;
		exit(0);
	}

	int nds = 2 * (n + n - 1);
	int edg = nds * n / 2;

	cout << "YES" << endl;
	cout << nds << " " << edg << endl;

	cout << 1 << " " << 2 * n << endl;
	print(1, n);
	print(2 * n, n);

	return 0;
}