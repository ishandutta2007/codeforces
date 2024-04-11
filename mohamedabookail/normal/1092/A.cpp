/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k; char ch = 'a';
		for (int i = 1; i <= n; i++) {
			cout << ch;
			ch++;
			if(!(i % k)) {
				ch = 'a';
			}
		} cout << endl;
	}
}