/**
 *    author:  Mohamed Abo_Okail
 *    created: 20/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	deque < int > dq(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> dq[i];
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		for (int j = 0; j < n; j++) {
			if(a >= dq[0]) {
				dq.pop_front();
				ans++; n--;
				break;
			}
			else {
				dq.pop_front();
				n--; j--;
			}
		}
		if(!dq.size()) { break; }
	}
	cout << ans << endl;
}