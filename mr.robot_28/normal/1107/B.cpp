#include<bits/stdc++.h> 
using namespace std;
int main () { 
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		long long a, b;
		cin >> a >> b;
		cout << 9 * (a - 1) + b << endl;
	}
	return 0;
}