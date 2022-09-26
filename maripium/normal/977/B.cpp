#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;string s; map<string,int> mp;
	cin >> n >> s;
	string sres;int res = 0;
	for (int i = 0;i < n - 1;++i) {
		string tmp = s.substr(i, 2);
		mp[tmp]++;
		if (mp[tmp] > res) {
			res = mp[tmp];
			sres = tmp;
		}
	} 
	
	cout << sres;
}