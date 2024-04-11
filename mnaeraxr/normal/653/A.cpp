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

	int n; cin >> n;

	vi v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	for (int i = 2; i < n; ++i){
		if (v[i] - v[i - 2] == 2 && v[i] - v[i - 1] == 1){
			cout << "YES" << endl;
			exit(0);
		}
	}

	cout << "NO" << endl;


	return 0;
}