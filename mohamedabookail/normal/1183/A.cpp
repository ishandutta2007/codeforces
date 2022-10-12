/**
 *    author:  Mohamed.Abo_Okail
 *    created: 12/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	while(true)
	{
		int cnt = 0, m = n;
		while(m) {
			cnt += m % 10;
			m /= 10;
		}

		if(!(cnt % 4)) {
			cout << n << endl;
			break;
		}
		else {
			n++;
		}
	}
}