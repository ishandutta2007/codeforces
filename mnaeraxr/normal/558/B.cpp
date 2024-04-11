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

int T[MAXN], B[MAXN], E[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int t = 0;
	for (int i = 1; i <= n; ++i){
		int v; cin >> v;
		if (!B[v]) B[v] = i;
		E[v] = i;
		t = max(t, ++T[v]);
	}

	int cur = -1;

	for (int i = 0; i < MAXN; ++i){
		if (T[i] == t){
			if (cur == -1 || E[cur] - B[cur] > E[i] - B[i])
				cur = i;
		}
	}
	cout << B[cur] << " " << E[cur] << endl;

	return 0;
}