#include<iostream>
using namespace std;
typedef long long LL;
int dp[400000][2];
int m[400000][2];
int main(){
  int n, k;
  cin >> n >> k;
  int a[n];
  int b[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  int c[n];
  for(int i = 0; i < n; i++) c[i] = a[i]-k*b[i];
  for(int i = 0; i < 400000; i++){
	  dp[i][0] = 0;
	  dp[i][1] = 0;
	  m[i][0] = 0;
	  m[i][1] = 0;
  }
  dp[200000][0] = 1;
  for(int i = 0; i < n; i++){
	  for(int j = 100000; j <= 300000; j++){
		  if(dp[j][0]){
			  //j+c[i]
			  dp[j+c[i]][1] = 1;
			  m[j+c[i]][1] = m[j][0]+a[i];
		  }
	  }
	  for(int j = 0; j < 400000; j++){
		  if(dp[j][0]){
			  if(dp[j][1]){
				  m[j][1] = max(m[j][1], m[j][0]);
			  } else {
				  dp[j][1] = dp[j][0];
				  m[j][1] = m[j][0];
			  }
		  }
		  dp[j][0] = dp[j][1];
		  m[j][0] = m[j][1];
		  dp[j][1] = 0;
		  m[j][1] = 0;
	  }
  }
  if(m[200000][0] > 0){
	  cout << m[200000][0] << endl;
  } else {
	  cout << -1 << endl;
  }
  return 0;
}