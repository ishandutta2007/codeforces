#include <bits/stdc++.h>

using namespace std;

int main() { 
	int n,m;
	cin >> n >> m;

	if( min(n,m) & 1 ) 
		cout << "Akshat" << endl;
	else
		cout << "Malvika" << endl;
}