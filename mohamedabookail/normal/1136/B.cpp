/**
 *    author:  Mohamed.Abo_Okail
 *    created: 20/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;

	if(k == 1 || n == k)
		cout << n * 3 << endl;
	else
		cout << n * 3 + min((n - k), (k - 1)) << endl;

}