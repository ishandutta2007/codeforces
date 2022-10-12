/**
 *    author:  Mohamed.Abo_Okail
 *    created: 28/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		string a, b, c;
		cin >> a >> b >> c;
		map <char, int> mp;
		int cnt = 0; bool bb = 1;
		for (int i = 0; i < c.size(); i++) {
			mp[c[i]]++;
		}
		for (int i = 0; i < b.size(); i++) {
			if(cnt < a.size() && b[i] == a[cnt]) {
				cnt++;
			}
			else if(mp[b[i]] > 0) {
				mp[b[i]]--;
			}
			else {
				bb = 0;
				break;
			}
		}
		cout << ((bb && cnt == a.size()) ? "YES" : "NO") << endl;
	}
}