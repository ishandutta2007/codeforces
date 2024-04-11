#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int ans[n];
	for (int i = 0; i < n; ++i) cin >> ans[i];
	int minimum = ans[0];
	for (int i = 0; i < n; ++i) minimum = (minimum > ans[i]) ? ans[i] : minimum;
	cout << 2 + (ans[2] ^ minimum);
	return 0;
}