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

int F[MAXN];
int C[MAXN];
char M[100][100];

int root(int a){
	return a == F[a] ? a : F[a] = root(F[a]);
}

bool join(int a, int b){
	a = root(a), b =  root(b);
	if (a == b) return false;
	if (C[a] > C[b]) swap(a, b);
	C[b] += C[a];
	F[a] = b;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> M[i];

	for (int i = 0; i < n * m; ++i){
		F[i] = i;
		C[i] = 1;
	}

	bool ok = false;

	for (int i = 0; i < n && !ok; ++i){
		for (int j = 0; j < m && !ok; ++j){
			if (i && M[i][j] == M[i - 1][j]){
				if (!join(i * m + j, (i - 1) * m + j))
				{
					ok = true;
				}
			}
			if (j && M[i][j] == M[i][j - 1]){
				if (!join(i * m + j, i * m + j - 1))
				{
					ok = true;
				}
			}
		}
	}

	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}