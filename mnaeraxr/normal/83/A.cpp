#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 ans = 0;

	int last = 0;
	int64 tot = 0;

	int n; cin >> n;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		if (v != last){
			last = v;
			tot = 0;
		}
		if (v == last)
			tot++;

		ans += tot;
	}

	cout << ans << endl;


	return 0;
}