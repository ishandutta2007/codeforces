#include <iostream>

using namespace std;

int main(){
  int n,t,a[30000];
  cin >> n >> t;
  for(int i =0; i< n-1; i++){
  	cin >> a[i];
  }
  int i;
  for(i =0; i + 1 < t; ){
 	i += a[i];
  }
  if(i == t-1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}