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

int64 pascal[20][20];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
			if (!j || !i) pascal[i][j] = 1;
			else pascal[i][j] = pascal[i - 1][j] + pascal[i][j - 1];

	int n; cin >> n;
	cout << pascal[n - 1][n - 1] << endl;

	return 0;
}