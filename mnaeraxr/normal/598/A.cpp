#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int64 solve(int64 v){
	int64 ans = v * (v + 1) / 2;
	ans -= 2 * ((1LL << (__lg(v) + 1)) - 1);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--){
		int64 v; cin >> v;
		cout << solve(v) << endl;
	}

	return 0;
}