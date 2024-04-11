/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int a, b; cin >> a >> b;
	for (int i = a; i <= b; i++) {
		int cnt = 0, x = i;
		set <int> st;
		while(x) {
			cnt++;
			st.insert(x % 10);
			x /= 10;
		}
		if(st.size() == cnt) {
			return cout << i << endl, 0;
		}
	} cout << -1 << endl;
}