#include<iostream>
using namespace std;
typedef long long LL;

int main(){
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int sums[k];
  for(int i = 0; i < k; i++){
	  sums[i] = 0;
	  for(int j = 0; j < n/k; j++){
		  sums[i] += a[i+k*j];
	  }
  }
  int m = 1000000000;
  for(int i = 0; i < k; i++) m = min(m, sums[i]);
  for(int i = 0; i < k; i++){
	  if(sums[i] == m){
		  cout << i+1 << endl;
		  return 0;
	  }
  }
}