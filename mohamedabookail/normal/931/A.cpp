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
	int a, b; cin >> a >> b;
	int c = (a + b) / 2;
	a = abs(a - c); b = abs(b - c);
	cout << (a * (a + 1) / 2) + (b * (b + 1) / 2) << endl;
}