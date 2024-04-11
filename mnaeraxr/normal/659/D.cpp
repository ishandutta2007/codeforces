#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100000 + 10;

int move(int a, int b){
	if (a == 0 && b > 0) return 0;
	if (b == 0 && a > 0) return 1;
	if (a == 0) return 2;
	return 3;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> v(n + 1);
	for (int i = 0; i <= n; ++i){
		cin >> v[i].first >> v[i].second;
	}

	int ans = 0;

	for (int i = 1; i < n; ++i){
		int m1 = move(v[i].first - v[i - 1].first, v[i].second - v[i - 1].second);
		int m2 = move(v[i + 1].first - v[i].first, v[i + 1].second - v[i].second);
		if ((m2 + 1) % 4 == m1) ++ans;
	}

	cout << ans << endl;

	return 0;
}