/**
 *    author:  Mohamed.Abo_Okail
 *    created: 21/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if(a[0] + a[1] > a[2])
		cout << 0 << endl;
	else 
		cout << a[2] - a[1] - a[0] + 1 << endl;

}