#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;

// TCR
// Computes the Z array in linear time
// z[i] is the length of the longest common prefix of substring
// starting at i and the string
// You can use string s instead of vector<int> s
// z[0]=0 by definition
vector<int> zAlgo(string s) {
	int n=s.size();
	vector<int> z(n);
	int l=0;int r=0;
	for (int i=1;i<n;i++) {
		z[i]=max(0, min(z[i-l], r-i));
		while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
		if (i+z[i]>r) {
			l=i;r=i+z[i];
		}
	}
	return z;
}

const int N = 5000 + 10;
int lst[N];
int dp[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) dp[i] = INF;

	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		string lol;
		for (int j = i; j < n; ++j) lol.push_back(str[j]);

		vector<int> z = zAlgo(lol);

		for (int j = 1; i+j < n; ++j) {
			lst[i+j] = max(lst[i+j], min(z[j], j));
		}
	}

	dp[0] = a;
	for (int i = 1; i < n; ++i) {
		if (dp[i-1] == INF) continue;

		int j = i + lst[i] - 1;
		dp[i] = min(dp[i], dp[i-1] + a);
		dp[j] = min(dp[j], dp[i-1] + b);
	}
	cout << dp[n-1] << '\n';
}