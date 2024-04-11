/**
 *    author:  Mohamed Abo_Okail
 *    created: 24/O1/2O2O
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
	int ar[3]; cin >> ar[0] >> ar[1] >> ar[2];
	sort(ar, ar + 3);
	cout << (ar[2] - ar[1]) + (ar[1] - ar[0]) << o_o;
}