/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	cout << n / 2 << endl;
	for (int i = 0; i < ((n / 2) - (n % 2)); i++) {
		cout << 2 << " ";
	}
	if(n % 2) {
		cout << 3 << endl;
	}
}