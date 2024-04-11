#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int t[4][5010];
int c[4];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i){
		int v; cin >> v;
		t[v][c[v]++] = i;
	}

	int ans = min(c[1], min(c[2], c[3]));
	cout << ans << endl;
	for (int i = 0; i < ans; ++i)
		cout << t[1][i] << " " << t[2][i] << " " << t[3][i] << endl;

	return 0;
}