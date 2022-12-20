#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
int dp[maxn],a[maxn],m[maxn],n,ans;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	ans = 1;
	for(int i = 1; i <= n; ++i){
		dp[i] = 1;
		vector <int> d;
		for(int j = 2; j * j <= a[i]; ++j)
			if(a[i] % j == 0) d.push_back(j), d.push_back(a[i] / j);
		d.push_back(a[i]);

		for(int x : d)
			dp[i] = max(dp[i], m[x] + 1);
		for(int x : d)
			m[x] = max(dp[i], m[x]);
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);
	return 0;
}