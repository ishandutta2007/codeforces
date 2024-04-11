#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int week[8] = {0, 52, 52, 52, 52, 53, 53, 52};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string a, b;
	cin >> a >> b;

	if (b == "week"){
		cout << week[n] << endl;
	}
	else{
		if (n <= 29) cout << 12 << endl;
		else if (n == 30) cout << 11 << endl;
		else cout << 7 << endl;
	}

	return 0;
}