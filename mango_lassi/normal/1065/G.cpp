#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = (ll)1e18;

// TCR ( https://github.com/Laakeri/contestlib/blob/master/src/string/z.cpp )
int zAlgo(string s, int k) {
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

	int res = 0;
	for (int i = k+1; i < z.size(); ++i) {
		if (z[i] >= k) ++res;
	}
	return res;
}

int matches(const string& str, const string& pat) {
	string tmp = pat + "#" + str;
	return zAlgo(tmp, pat.size());
}

const int N = 17;
string dp[N];

// How many suffices match str
ll test(const string& str, ll n) {
	if (n < N) {
		return matches(dp[n], str);
	} else {
		int a = N - 2;
		int b = N - 1;
		int len = (int)str.size() - 1;
		string a_start (len, 'a');
		string a_end (len, 'a');
		string b_start (len, 'b');
		string b_end (len, 'b');
		for (int i = 0; i < len; ++i) a_start[i] = dp[a][i];
		for (int i = 0; i < len; ++i) a_end[i] = dp[a][i + (dp[a].size() - len)];
		for (int i = 0; i < len; ++i) b_start[i] = dp[b][i];
		for (int i = 0; i < len; ++i) b_end[i] = dp[b][i + (dp[b].size() - len)];

		ll a_cou = matches(dp[N-2], str);
		ll b_cou = matches(dp[N-1], str);

		while(b < n) {
			if (b_cou > INF) return b_cou;

			// Fix counts
			swap(a_cou, b_cou);
			string tmp = a_end + b_start;
			b_cou = a_cou + b_cou + matches(tmp, str);

			// Fix starts and ends
			swap(a_start, b_start);
			a_end = b_end;

			++a;
			++b;
		}
		return b_cou;
	}
}

int main() {	
	ll n, k, m;
	cin >> n >> k >> m;

	dp[0] = "0";
	dp[1] = "1";
	for (int i = 2; i < N; ++i) dp[i] = dp[i-2] + dp[i-1];

	string res = "";
	for (int i = 0; i < m; ++i) {
		res.push_back('0');
		ll cou = test(res, n);
		if (cou < k) {
			k -= cou;
			res.back() = '1';
		}
		// If res is a suffix, decrement k
		bool suff = true;
		for (int j = 0; j < res.size(); ++j) {
			if (dp[N-1][dp[N-1].size() - res.size() + j] != res[j]) suff = false;
		}
		if (suff) --k;
		if (k == 0) break;
	}
	cout << res << '\n';
}