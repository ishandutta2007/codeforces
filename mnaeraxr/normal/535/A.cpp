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

/*
	zero (nought)	10	ten
1	one	11	eleven
2	two	12	twelve (a dozen)	20	twenty (a score)
3	three	13	thirteen	30	thirty
4	four	14	fourteen	40	forty (no "u")
5	five	15	fifteen (note "f", not "v")	50	fifty (note "f", not "v")
6	six	16	sixteen	60	sixty
7	seven	17	seventeen	70	seventy
8	eight	18	eighteen (only one "t")	80	eighty (only one "t")
9	nine	19	nineteen	90	ninety (note the "e")
 */

string ans[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string teen[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
					"sixteen", "seventeen", "eighteen", "nineteen"};
string ddd[10] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	if (n < 10) cout << ans[n] << endl;
	else if (n < 20) cout << teen[n - 10] << endl;
	else if (n % 10 == 0) cout << ddd[n / 10] << endl;
	else{
		cout << ddd[n / 10] << "-" << ans[n % 10] << endl;
	}

	return 0;
}