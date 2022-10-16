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
const int MAXN = (int)5e2 + 10;
const int64 MOD = (int64)1e9 + 7;

int preorder[MAXN];
int64 memo[MAXN][MAXN];
bool ok[MAXN][MAXN];

int64 solve(int b, int e){
	if (ok[b][e]) return memo[b][e];
	ok[b][e] = true;
	int64 &val = memo[b][e];
	if (e <= b) {
		val = 1;
		return val = 1;
	}
	val = 0;
	for (int i = b + 1; i <= e; ++i){
		if (preorder[b] < preorder[i]){
			val += solve(b + 1, i - 1) * solve(i, e) % MOD;
			val %= MOD;
		}
	}
	val += solve(b + 1, e);
	val %= MOD;
	return val;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> preorder[i];

	cout << solve(1, n - 1) << endl;

	return 0;
}