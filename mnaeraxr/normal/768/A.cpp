#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> S(n);

	int mn = oo, mx = -1;

	for (int i = 0; i < n; ++i){
		cin >> S[i];

		mn = min(mn, S[i]);
		mx = max(mx, S[i]);
	}

	int cnt_mn = 0, cnt_mx = 0;

	for (int i = 0; i < n; ++i){
		if (mn == S[i]) cnt_mn++;
		if (mx == S[i]) cnt_mx++;
	}

	int answer = max(0, n - cnt_mn - cnt_mx);

	cout << answer << endl;

	return 0;
}