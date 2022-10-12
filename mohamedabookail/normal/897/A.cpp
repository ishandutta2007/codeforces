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
	
	int n, m;
	string s;
	cin >> n >> m >> s;
	while(m--) {
		int x, y;
		char a, b;
		cin >> x >> y >> a >> b;
		for (int i = (x - 1); i < y; i++) {
			if(s[i] == a) {
				s[i] = b;
			}
		}
	}
	cout << s << endl;
}