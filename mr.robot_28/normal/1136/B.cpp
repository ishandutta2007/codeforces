#include<bits/stdc++.h> 

using namespace std; 

int main() { 
	int n, k;
	cin >> n >> k;
	cout << n + 1 + min(2 * n - k - 1, k + n - 2) + n;
	return 0;
}