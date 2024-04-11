#include <iostream>
#define MAXN 100005
using namespace std;
typedef long long int ll;

int cnt[MAXN], n;
ll dp[MAXN][2];

int main(){
	int i, t;
	cin >> n;
	for(i = 1; i <= n; ++ i)
		cin >> t, cnt[t] ++;
	for(i = 1; i <= 100000; ++ i){
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
		dp[i][1] = dp[i - 1][0] + (ll)i * cnt[i];
	}
	cout << max(dp[100000][0], dp[100000][1]) << endl;
	return 0;
}