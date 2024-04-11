#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
double dp[210000][2];
int n, zz;
double t[210000];
double sum1[210000];
double sum2[210000];
double add1(int a, int b){
	if(b < a) return 0;
	if(a == 0) return sum1[b];
	return sum1[b]-sum1[a-1];
}
double add2(int a, int b){
	if(b < a) return 0;
	if(a == 0) return sum2[b];
	return sum2[b]-sum2[a-1];
}
void solve(int a, int b, int l, int r, int i){
	int m = (a+b)/2;
	int idx = -1;
	dp[m][i%2] = 0;
	for(int k = l; k <= r; k++){
		if(k == 0) continue;
		if(k >= m) break;
		double z = dp[k][1-i%2] + add1(0,k-1) * add2(k,m-1);
		if(z > dp[m][i%2]){
			dp[m][i%2] = z;
			idx = k;
		}
	}
	if(a < m){
		solve(a, m-1, l, idx, i);
	}
	if(m<b){
		solve(m+1,b, idx, r, i);
	}

}
int main(){
	scanf("%d%d", &n, &zz);
	for(int i = 0; i < n; i++){
		scanf("%lf", &t[i]);
		sum1[i] = t[i];
		sum2[i] = 1.0/t[i];
		if(i > 0){
			sum1[i] += sum1[i-1];
			sum2[i] += sum2[i-1];
		}
	}
	double ans = 0;
	double r = 0;
	for(int i = 0; i < n; i++){
		r += t[i];
		ans += r/t[i];
	}
	for(int i = 0; i < n; i++){
		dp[i][0] = 0;
		dp[i][1] = 0;
	}
	for(int i = 2; i <= zz; i++){
		solve(0,n,1,n,i);
	}
	printf("%.11lf\n", ans-dp[n][zz%2]);
}