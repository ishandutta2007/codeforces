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
const int MAXN = (int)1e2 + 10;

bool M[MAXN][MAXN];

bool valid(int n, int m)
{
	for (int j = 0; j < m; ++j){
		for (int i = 0; i < n; ++i){
			if (M[i][j] != M[2 * n - i - 1][j])
				return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			cin >> M[i][j];
	}


	while (n % 2 == 0 && valid(n / 2, m)) n /= 2;

	cout << n << endl;

	return 0;
}