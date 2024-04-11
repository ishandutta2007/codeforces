/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10; 
int a[maxN];
long long dp[maxN];

int main() { 
	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++ ) { 
		int num;
		cin >> num; 
		a[num]++;
	}

	dp[1] = 1*a[1];
	for(int i = 2 ; i < maxN ; i++ ) { 
		dp[i] = max( 1LL*i*a[i] + dp[i-2] , dp[i-1] ) ; 
	}

	cout << dp[maxN-1] << endl;
}