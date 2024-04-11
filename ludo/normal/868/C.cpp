#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int cnt[16] = {};
bool has[16] = {};

bool run()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int num = 0;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			num = 2 * num + x;
		}
		// pad with zeros...
		cnt[num]++;
		has[num] = true;
	}
	/*
	if (has[0]) return true;
	int sum1 = has[1] + has[2] + has[4] + has[8];
	if (sum1 >= 2) return true;
	*/
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (!has[i] || !has[j]) continue;
			if ((i & j) == 0) return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	(cout << fixed).precision(18);

	bool ans = run();
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}