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
	if(n % 10 >= 5) {
		cout << n - n % 10 + 10 << endl;
	}
	else {
		cout << n - n % 10 << endl;
	}
}