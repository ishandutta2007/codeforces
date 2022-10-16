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

bool B[1010][1010];
int n, m, k;

bool isBlack(int x, int y){
	if (x < 1 || x >= n || y < 1 || y >= m) return false;
	return B[x][y] && B[x + 1][y] && B[x][y + 1] && B[x + 1][y + 1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i){
		int x, y; cin >> x >> y;
		B[x][y] = true;
		if (isBlack(x, y) || isBlack(x - 1, y) || isBlack(x, y - 1) || isBlack(x - 1, y - 1))
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;

	return 0;
}