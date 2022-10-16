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
const int MAXN = (int)2e5 + 10;

int F[MAXN];

void build_pi(vector<int> &s){
	int k = F[0] = -1;
	for (int i = 1; i < SZ(s); ++i)
	{
		while (k >= 0 && s[k + 1] != s[i]) k = F[k];
		if (s[k + 1] == s[i]) k++;
		F[i] = k;
	}
}

int match(vector<int> &s, vector<int> &p){
	build_pi(p);
	int cnt = 0, k = -1;
	for (int i = 0; i < SZ(s); ++i)
	{
		while (k >= 0 && p[k + 1] != s[i]) k = F[k];
		if (p[k + 1] == s[i]) k++;
		if (k + 1 == SZ(p))
		{
			cnt++;
			k = F[k];
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (m == 1){
		cout << n << endl;
		exit(0);
	}

	if (n == 1){
		cout << 0 << endl;
		exit(0);
	}

	vector<int> V(n - 1);
	int cur; cin >> cur;
	for (int i = 0; i < n - 1; ++i){
		int v; cin >> v;
		V[i] = v - cur;
		cur = v;
	}

	vector<int> T(m - 1);
	cin >> cur;
	for (int i = 0; i < m - 1; ++i){
		int v; cin >> v;
		T[i] = v - cur;
		cur = v;
	}

	cout << match(V, T) << endl;

	return 0;
}