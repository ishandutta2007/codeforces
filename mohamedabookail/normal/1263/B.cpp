/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector <string> v(n);
		map <string, int> mp;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mp[v[i]]++;
		}
		for (int i = 0; i < n; i++) {
			stack <string> st;
			vector <ll> ans;
			if(mp[v[i]] > 1) {
				mp[v[i]]--;
				int e = mp[v[i]], inx = 0;
				cnt += e;
				char ch = '0';
				for (int j = 0; j < e; j++) {
					string a = v[i];
					if(a[inx] != ch) {
						a[inx] = ch;
						if(mp[a] != 1) {
							mp[a] = 1;
							st.push(a);
						}
						else { j--; }
					}
					else { j--; }
					if(ch == '9') {
						inx++;
						ch = '0';
					}
					else { ch++; }
				}
				mp[v[i]] = 1;
			}
			for (int j = (i + 1); j < n; j++) {
				if(v[i] == v[j]) {
					v[j] = st.top();
					st.pop();
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < n; i++) {
			cout << v[i] << endl;
		}
	}
}