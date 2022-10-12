/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	set < int > st;
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		if(oo) { st.insert(oo); }
	}
	cout << st.size() << endl;
}