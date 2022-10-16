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

int64 ans;
int n;
int V[3000];
int M[3000];

void dfs1(int s, int d)
{
	if (d == n) M[s] = 0;
	else{
		dfs1(2 * s, d + 1);
		dfs1(2 * s + 1, d + 1);
		M[s] = max(V[2 * s] + M[2 * s], V[2 * s + 1] + M[2 * s + 1]);
	}
}

void dfs2(int s, int d)
{
	if (s != 1){
		ans += M[s / 2] - M[s] - V[s];
	}
	if (d < n){
		dfs2(2 * s, d + 1);
		dfs2(2 * s + 1, d + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 2; i <= (1 << (n + 1)) - 1; ++i)
		cin >> V[i];

	ans = 0;
	dfs1(1, 0);
	dfs2(1, 0);

	cout << ans << endl;

	return 0;
}