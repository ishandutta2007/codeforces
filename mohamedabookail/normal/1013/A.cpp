/**
 *    author:  Mohamed Abo_Okail
 *    created: 20/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	ll a = 0, b = 0, x;
	for (int i = 0; i < n; i++) {
		cin >> x; a += x;
	}
	for (int i = 0; i < n; i++) {
		cin >> x; b += x;
	}
	if(a >= b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}