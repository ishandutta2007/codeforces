#include<iostream>
using namespace std;
typedef long long LL;

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  int a[3];
  a[1] = 0;
  a[2] = 0;
  for(int i = 0; i < n; i++){
	  int c;
	  cin >> c;
	  a[c]++;
  }
  int ans = 0;
  int r = min(m, a[1]);
  m -= r;
  a[1] -= r;
  cout << a[1]+a[2]-min(m+k, a[2]) << endl;
}