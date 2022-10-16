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
const int MAXN = (int)1e6 + 10;

//int ANS[1010][1010];
//int n, k, d;
//
//void next(int c){
//	for (int i = 0; i < d; ++i){
//		if (ANS[i][c] == k) ANS[i][c] = 1;
//		else{
//			ANS[i][c]++;
//			break;
//		}
//	}
//	for (int i = 0; i < d; ++i)
//		ANS[i][c + 1] = ANS[i][c];
//}

int L[MAXN], R[MAXN], V[MAXN];
map<int,int> M;

int BIT[MAXN];

void update(int idx){
	while (idx < MAXN){
		BIT[idx]++;
		idx += idx & -idx;
	}
}

int read(int idx){
	int ans = 0;
	while (idx){
		ans += BIT[idx];
		idx -= idx & -idx;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> V[i];
		L[i] = ++M[V[i]];
	}
	M.clear();
	for (int i = n - 1; i >= 0; --i){
		R[i] = ++M[V[i]];
	}

	int64 ans = 0;
	for (int i = n - 1; i >= 0; --i){
		ans += read(L[i] - 1);
		update(R[i]);
	}

	cout << ans << endl;

	return 0;
}