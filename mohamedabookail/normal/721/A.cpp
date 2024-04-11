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
	
	int n; string s;
	cin >> n >> s;
	s += '0';
	vector <int> ans;
	int c = 0;
	for (int i = 0; i <= n; i++) {
		if(s[i] == 'B') {
			c++;
		}
		else {
			if(c) {
				ans.push_back(c);
			}
			c = 0;
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}