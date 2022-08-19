#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[2][5001]; // p+1, p
int main(){
	LL n, k;
	cin >> n >> k;
	LL a[n];
	for(LL i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	LL c = n%k;
	LL p = n/k; // c with p+1, (k-c) with p
	dp[0][0] = 0;
	for(LL i = 0; i <= c; i++){
		for(LL j = 0; j <= (k-c); j++){
			if(i+j>0) dp[i%2][j] = 1000000000000000;
			if(i > 0){
				dp[i%2][j] = min(dp[i%2][j], dp[1-i%2][j]+a[i*(p+1)+j*p-1]-a[(i-1)*(p+1)+j*p]);
			}
			if(j>0){
				dp[i%2][j] = min(dp[i%2][j], dp[i%2][j-1]+a[i*(p+1)+j*p-1]-a[i*(p+1)+(j-1)*p]);
			}
		}
	}
	cout << dp[c%2][k-c] << endl;





}