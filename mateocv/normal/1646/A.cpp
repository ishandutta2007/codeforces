#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		long long n, s; 
		cin >> n >> s;
		cout << s / (n * n) << "\n";
	}
	return 0;
}