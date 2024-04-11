/**
*    author:  Mohamed AboOkail
*    created: 11/01/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector < string > a(n);
	map < string , int > mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		mp[s]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if(!mp[a[i]]) ans++;
		else mp[a[i]]--;
	}
	cout << ans << endl;
}