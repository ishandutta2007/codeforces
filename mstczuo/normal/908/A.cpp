# include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	set<char> S({'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'});
	for(auto c: s) if(S.count(c)) cnt++;
	cout << cnt << endl;
}