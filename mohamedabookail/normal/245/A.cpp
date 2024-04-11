/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	int cntA1 = 0, cntA2 = 0, cntB1 = 0, cntB2 = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			cntA1 += b;
			cntA2 += c;
		}
		else {
			cntB1 += b;
			cntB2 += c;
		}
	}
	if(cntA1 >= cntA2) {
		cout << "LIVE" << endl;
	}
	else {
		cout << "DEAD" << endl;
	}
	if(cntB1 >= cntB2) {
		cout << "LIVE" << endl;
	}
	else {
		cout << "DEAD" << endl;
	}
}