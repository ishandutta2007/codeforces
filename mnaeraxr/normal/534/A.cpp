#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	if (n == 3){
		cout << 2 << endl << 1 << " " << 3 << endl;
	}
	else{
		if (n == 2) n--;
		cout << n << endl;
		if (n & 1) cout << n << " ", --n;
		for (int i = n - 1; i > 0; i-= 2)
			cout << i << " ";
		for (int i = n; i > 0; i -= 2)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}