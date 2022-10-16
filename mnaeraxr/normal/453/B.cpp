#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;

int lst[60], tPrimes;
int fact[60];
pii dp[101][1 << 18];
int inp[101];
int MMM = 60;

bool isPrime(int v){
	int i = 2;
	while (i * i <= v){
		if (v % i == 0) 
			return false;
		i += 1;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tPrimes = 0;
	for (int i = 2; i < MMM; ++i)		
		if (isPrime(i)) lst[tPrimes++] = i;

	for (int i = 2; i < MMM; ++i)
		for (int j = 0; j < tPrimes; ++j)
			if (i % lst[j] == 0) 
				fact[i] |= (1 << j);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> inp[i];

	memset(dp, oo, sizeof dp);
	dp[0][0] = {0, -1};

	for (int i = 1; i <= n; ++i){
		for (int k = 1; k < MMM; ++k){
			int mask = (~fact[k]) & ((1 << tPrimes) - 1);
			for (int sm = mask; ; sm = mask & (sm - 1)){
				int curVal = dp[i - 1][sm].first + abs(k - inp[i]);
				if (curVal < dp[i][sm | fact[k]].first){
					dp[i][sm | fact[k]] = {curVal, k};
				}
				if (sm == 0) break;
			}
		}
	}

	int mask = 0;
	for (int i = 0; i < (1 << tPrimes); ++i)
		if (dp[n][i].first < dp[n][mask].first)
			mask = i;

	vector<int> ans;
	for (int i = n; i; --i){
		ans.push_back(dp[i][mask].second);
		mask ^= fact[dp[i][mask].second];
	}

	reverse(ans.begin(), ans.end());
	for (auto v : ans)
		cout << v << " ";
	cout << endl;

	return 0;
}