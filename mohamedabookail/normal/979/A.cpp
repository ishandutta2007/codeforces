/**
 *    author:  Mohamed Abo_Okail
 *    created: O2/O2/2O2O
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
	ll n; cin >> n; n++;
	if(n == 1) cout << 0;
	else if(!(n % 2)) cout << n / 2;
	else cout << n;
}