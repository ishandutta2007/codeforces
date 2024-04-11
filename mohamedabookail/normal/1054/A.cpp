/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main() 
{
	std::ios_base::sync_with_stdio(0);
	int a, b, c, t1, t2, t3;
	cin >> a >> b >> c >> t1 >> t2 >> t3;
	int nemo = abs(a - b) * t1;
	int nemoo = abs(a - c) * t2 + abs(a - b) * t2 + (3 * t3);
	cout << (nemo >= nemoo ? "YES" : "NO") << o_o;
}