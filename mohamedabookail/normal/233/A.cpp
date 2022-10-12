/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	if(n % 2) { cout << -1; }
	else {
		for (int i = 1; i <= n; i++) {
			if(i % 2) {
				cout << i + 1 << ' ';
			}
			else {
				cout << i - 1 << ' ';
			}
		}
	}
}