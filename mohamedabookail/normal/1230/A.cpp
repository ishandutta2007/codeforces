/**
 *    author:  Mohamed.Abo_Okail
 *    created: 26/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int sum = (a + b + c + d);
	if(sum % 2) { cout << "NO" << endl; }
	else {
		sum /= 2;
		if(sum == a + b || sum == a + c || sum == a + d) {
			cout << "YES" << endl;
		}
		else if(sum == a || sum == b || sum == c || sum == d) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}