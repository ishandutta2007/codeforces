#include<iostream>
using namespace std;
typedef long long LL;

int main(){
  int n, m;
  cin >> n >> m;
  int t[m], l[m], r[m], d[m];
  for(int i = 0; i < m; i++){
	  cin >> t[i] >> l[i] >> r[i] >> d[i];
	  l[i]--;
	  r[i]--;
  }
  int a[n];
  for(int i = 0; i < n; i++){
	  a[i] = 200000000;
  }
  for(int i = 0; i < m; i++){
	  if(t[i] == 1){
		  for(int j = l[i]; j <= r[i]; j++){
			  a[j] += d[i];
		  }
	  } else {
		  int k = 0;
		  for(int j = l[i]; j <= r[i]; j++){
			  a[j] = min(a[j], d[i]);
			  if(a[j] == d[i]) k = 1;
		  }
		  if(k == 0){
			  cout << "NO" << endl;
			  return 0;
		  }
	  }
  }
  for(int i = 0; i < m; i++){
	  if(t[i] == 1){
		  for(int j = l[i]; j <= r[i]; j++){
			  a[j] -= d[i];
		  }
	  }
  }
  for(int i = 0; i < m; i++){
  	  if(t[i] == 1){
  		  for(int j = l[i]; j <= r[i]; j++){
  			  a[j] += d[i];
  		  }
  	  } else {
  		  int k = -2000000000;
  		  for(int j = l[i]; j <= r[i]; j++){
  			  k = max(k,a[j]);
  		  }
  		  if(k != d[i]){
  			  cout << "NO" << endl;
  			  return 0;
  		  }
  	  }
  }
  for(int i = 0; i < m; i++){
  	  if(t[i] == 1){
  		  for(int j = l[i]; j <= r[i]; j++){
  			  a[j] -= d[i];
  		  }
  	  }
  }
  cout << "YES" << endl;
  for(int i = 0; i < n; i++){
	  cout << a[i] << " ";
  }
  cout << endl;
}