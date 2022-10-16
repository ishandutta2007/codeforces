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

bool dp[50][50][2];
int toprint = 10;

void win(int cur){
	if (cur) cout << "Stannis" << endl;
	else cout << "Daenerys" << endl;

	exit(0);
}

int getwin(int a, int b, int kk){
	if (kk & 1){
		if (b - a >= kk)
			return 1;
		if (a + b == kk)
			return b & 1;

		int x1 = 1, y1 = kk;
		for (; x1 <= kk; ++x1, --y1){
			if (a - y1 == b - x1)
				return 1;
		}
		return 0;
	}
	else{
		if (abs(b - a) >= kk)
			return 0;

		if (a + b == kk)
			return b & 1;

		int x1 = 1, y1 = kk;
		for (; x1 <= kk; ++x1, --y1){
			if (a - y1 == b - x1)
				return 1;
		}
		return 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, kk;
	cin >> n >> kk;
	int a = 0, b = 0;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;

		if (v & 1) ++b;
		else ++a;
	}

	win(getwin(a, b, kk));

	int k;
	cin >> k;

	for (int i = 0; i < toprint; ++i){
		for (int j = 0; j < toprint; ++j){
			dp[i][j][1] = getwin(i, j, k);
//			if (i + j < k) continue;
//			else if (i + j == k){
//				dp[i][j][1] = (j & 1);
//				dp[i][j][0] = 1 ^ dp[i][j][1];
//			}
//			else{
//				if (i && !dp[i - 1][j][0])
//					dp[i][j][1] = 1;
//				if (j && !dp[i][j - 1][0])
//					dp[i][j][1] = 1;
//
//				if (i && !dp[i - 1][j][1])
//					dp[i][j][0] = 1;
//				if (j && !dp[i][j - 1][1])
//					dp[i][j][0] = 1;
//			}
		}
	}

	cout << "x ";
	for (int i = 0; i < toprint; ++i)
		cout << i << " ";
	cout << endl;

	for (int j = 0; j < toprint; ++j){
		cout << j << " ";
		for (int k = 0; k < toprint; ++k)
			cout << dp[j][k][1] << " ";
		cout << endl;
	}
	cout << endl;


	return 0;
}