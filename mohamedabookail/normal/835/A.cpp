/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n, a, b, x, y;
	cin >> n >> a >> b >> x >> y; 
	int ans1 = (n * a) + (x * 2);
	int ans2 = (n * b) + (y * 2);
	if(ans1 < ans2) {
		cout << "First" << endl;
	}
	else if(ans2 < ans1) {
		cout << "Second" << endl;
	}
	else {
		cout << "Friendship" << endl;
	}
}