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

	int64 cur;
	cin >> cur;
	int64 tot = 2;
	int64 st = 1;

	int ans = 0;

	for (;tot <= cur;){
		if ((cur - tot) % 3 == 0) ++ans;
		tot = tot + st * 3 + 2;
		st++;
	}

	cout << ans << endl;



	return 0;
}