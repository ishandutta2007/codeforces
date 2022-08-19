#include<iostream>
using namespace std;
typedef long long LL;

int main(){
  int n, k, l, sall, sk;
  cin >> n >> k >> l >> l>> sall >> sk;
  for(int i = 0; i < k; i++){
	int r = sk/k;
	int m = sk-k*r;
	if(i < m){
		cout << r+1 << " ";
	} else {
		cout << r << " ";
	}
  }
  k = n-k;
  sk = sall-sk;
  for(int i = 0; i < k; i++){
	int r = sk/k;
	int m = sk-k*r;
	if(i < m){
		cout << r+1 << " ";
	} else {
		cout << r << " ";
	}
  }
}