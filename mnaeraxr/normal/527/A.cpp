#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

int64 solve(int64 a, int64 b){
	if (!a || !b) return 0;
	return b / a + solve(b % a, a);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 a, b;
	cin >> a >> b;

	cout << solve(a, b) << endl;

	return 0;
}