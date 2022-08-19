#include<iostream>
using namespace std;
typedef long long LL;
LL abso(LL a){
	if(a < 0) return -a;
	return a;
}
int main(){
  LL k, n;
  cin >> n >> k;
  LL a[n];
  for(LL i = 0; i < n; i++) cin >> a[i];
  if(n == 1){
	  cout << 0 << endl;
	  return 0;
  }
  LL s = -1;
  LL e = 2000000000;
  while(s+1<e){
	  LL m = (s+e)/2;
	  LL dp[n];
	  LL ans = n;
	  dp[0] = 0;
	  for(LL i = 1; i < n; i++){
		  dp[i] = i;
		  for(LL j = 0; j < i; j++){
			  if(abso(a[j]-a[i]) <= m*(i-j)){
				  dp[i] = min(dp[i], dp[j]+(i-j-1));
			  }
		  }
	  }
	 for(LL i = 0; i < n; i++){
		 ans = min(ans, dp[i]+n-1-i);
	 }
	 if(ans <= k){
		 e=m;
	 } else {
		 s=m;
	 }
  }
  cout << e << endl;
}