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
const int MAXN = (int)2e5 + 10;

vi ady[MAXN];
int64 V[MAXN];
int64 dp[MAXN][2];

void dfs(int s){
	int64 vMin = oo;
	int64 cVal = 0;
	int par = 0;

	for (int i = 0; i < (int)ady[s].size(); ++i){
		int nx = ady[s][i];
		dfs(nx);

		if (dp[nx][1] > dp[nx][0]) par ^= 1;
		cVal += max(dp[nx][1], dp[nx][0]);
		vMin = min(vMin, abs(dp[nx][0] - dp[nx][1]));
	}

	if (par == 0){
		dp[s][1] = cVal + V[s];
		dp[s][0] = cVal;
	}
	else{
		dp[s][1] = max(cVal, cVal - vMin + V[s]);
		dp[s][0] = cVal - vMin;
	}

//	cout << s << " " << par << " " << dp[s][0] << " " << dp[s][1] << endl;
//	cout << cVal << " " << vMin << endl;
//	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i){
		int f;
		cin >> f >> V[i];
		if (f != -1) ady[f].push_back(i);
	}

	dfs(1);

	cout << max(dp[1][1], dp[1][0]) << endl;

	return 0;
}