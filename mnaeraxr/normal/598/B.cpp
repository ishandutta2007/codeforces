#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	int t; cin >> t;
	while (t--){
		int l, r, k;
		cin >> l >> r >> k;
		--l;
		string tmp = s;
		for (int i = 0; i < r - l; ++i){
			int p = (i + k) % (r - l);
			s[p + l] = tmp[i + l];
		}
	}

	cout << s << endl;

	return 0;
}