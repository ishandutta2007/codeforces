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
	int n, m; cin >> n >> m;
	set < ll > st;
	while(n--) {
		int x; cin >> x;
		while(x--) {
			int oo; cin >> oo;
			st.insert(oo);
		}
	}
	cout << (st.size() == m ? "YES" : "NO") << o_o;
}