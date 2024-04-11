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

int ANS[1010][1010];
int n, k, d;

void next(int c){
	for (int i = 0; i < d; ++i){
		if (ANS[i][c] == k) ANS[i][c] = 1;
		else{
			ANS[i][c]++;
			break;
		}
	}
	for (int i = 0; i < d; ++i)
		ANS[i][c + 1] = ANS[i][c];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> d;

	int64 t = 1;
	for (int i = 0; i < d && t < n; ++i, t *= k);

	if (t < 1LL * n){
		cout << -1 << endl;
		exit(0);
	}

	for (int j = 0; j < d; ++j)
		ANS[j][0] = ANS[j][1] = 1;

	for (int i = 1; i < n; ++i){
		next(i);
	}

	for (int i = 0; i < d; ++i){
		for (int j = 0; j < n; ++j)
			cout << ANS[i][j] << " ";
		cout << endl;
	}

	return 0;
}