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

int64 M[MAXN][MAXN];
int64 A[MAXN], B[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int64 great = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> M[i][j];
			great = max(great, M[i][j]);
		}
	}
	int64 mod = 0;
	for (int i = 1; i < n && mod != 1; ++i){
		for (int j = 0; j < m && mod != 1; ++j)
			for (int k = j + 1; k < m && mod != 1; ++k){
				int64 d1 = M[i][j] - M[i - 1][j];
				int64 d2 = M[i][k] - M[i - 1][k];
				if (d1 != d2) mod = __gcd(mod, abs(d1 - d2));
			}
	}

	for (int i = 1; i < m && mod != 1; ++i){
		for (int j = 0; j < n && mod != 1; ++j)
			for (int k = j + 1; k < n && mod != 1; ++k){
				int64 d1 = M[j][i] - M[j][i - 1];
				int64 d2 = M[k][i] - M[k][i - 1];
				if (d1 != d2) mod = __gcd(mod, abs(d1 - d2));
			}
	}

	if (!mod) mod = great + 1;
	if (mod <= great){
		cout << "NO" << endl;
		return 0;
	}
	A[0] = 0;

	for (int i = 1; i < n; ++i){
		A[i] = M[i][0] - M[i - 1][0] + A[i - 1];
		A[i] = (A[i] % mod + mod) % mod;
	}

	for (int j = 0; j < m; ++j){
		B[j] = M[0][j] - A[0];
		B[j] = (B[j] % mod + mod) % mod;
	}

	bool ok = true;
	for (int i = 0; i < n && ok; ++i){
		for (int j = 0; j < m && ok; ++j){
			if ((A[i] + B[j]) % mod != M[i][j]) ok = false;
		}
	}

	if (ok){
		cout << "YES" << endl << mod << endl;
		for (int i = 0; i < n; ++i)
			cout << A[i] << " \n"[i + 1 == n];
		for (int i = 0; i < m; ++i)
			cout << B[i] << " \n"[i + 1 == m];
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}