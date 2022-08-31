#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int o = 1;
	int e = 2;
	int n;
	cin >> n;
	int k = (n-1)/2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i+j < k || j-i > k || i-j > k || i+j > (3*k)){
				cout << e << " ";
				e += 2;
			} else {
				cout << o << " ";
				o += 2;
			}
		}
		cout << endl;
	}
}