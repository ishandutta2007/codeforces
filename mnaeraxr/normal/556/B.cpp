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
	int dx; cin >> dx;
	dx = n - dx;
	for (int i = 1; i < n; ++i){
		int v; cin >> v;
		if (i & 1){
			if ((v - dx + n) % n != i){
				cout << "No" << endl;
				exit(0);
			}
		}
		else{
			if ((v + dx) % n != i){
				cout << "No" << endl;
				exit(0);
			}
		}
	}

	cout << "Yes" << endl;

	return 0;
}