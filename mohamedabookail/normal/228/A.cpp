/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/11/2019
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
	set <int> st;
	st.insert(a);
	st.insert(b);
	st.insert(c);
	st.insert(d);
	cout << 4 - st.size() << endl;
}