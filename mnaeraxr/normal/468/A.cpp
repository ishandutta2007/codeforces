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

	int n;
	cin >> n;
	if (n <= 3){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		if (n & 1){
			cout << "3 - 2 = 1" << endl;
			cout << "1 + 5 = 6" << endl;
			cout << "4 * 6 = 24" << endl;
			cout << "1 * 24 = 24" << endl;
			for (int i = 7; i <= n; i += 2){
				cout << i << " - " << i - 1 << " = 1" << endl;
				cout << "1 * 24 = 24" << endl;
			}
		}
		else{
			cout << "1 * 2 = 2" << endl;
			cout << "2 * 3 = 6" << endl;
			cout << "6 * 4 = 24" << endl;
			for (int i = 6; i <= n; i += 2){
				cout << i << " - " << i - 1 << " = 1" << endl;
				cout << "1 * 24 = 24" << endl;
			}
		}
	}

	return 0;
}