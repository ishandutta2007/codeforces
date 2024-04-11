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

bool check(int64 n, int64 a1, int64 a2, int64 a3){
	if (a1 < 0 || a2 < 0 || a3 < 0) return false;
	return max(a1, max(a2, a3)) * 3 <= n;
}

bool check1(int64 n, int64 k, int64 d1, int64 d2){
	int64 a1 = k + d2 + 2 * d1;
	if (a1 % 3) return false;
	a1 /= 3;
	int64 a2 = a1 - d1;
	int64 a3 = a2 - d2;
	return check(n, a1, a2, a3);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--){
		int64 n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;

		if ( n % 3 != 0){
			cout << "no" << endl;
			continue;
		}

		if (check1(n, k, d1, d2) || check1(n, k, -d1, d2) || check1(n, k, d1, -d2) || check1(n, k, -d1, -d2))
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

	return 0;
}