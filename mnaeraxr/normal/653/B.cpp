#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int to[6][6];
int ans;

void bt(int a, int n){
	if (n == 0){
		if (a == 0) ++ans;
		return;
	}

	for (int i = 0; i < 6; ++i)
		if (to[a][i] != -1)
			bt(to[a][i], n - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(to, -1, sizeof to);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; ++i){
		string a, b;
		cin >> a >> b;
		to[a[0] - 'a'][a[1] - 'a'] = b[0] - 'a';
	}

	for (int i = 0; i < 6; ++i){
		bt(i, n - 1);
	}

	cout << ans << endl;

	return 0;
}