/**
 *    author:  Mohamed.Abo_Okail
 *    created: 31/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int n; string s;
stack <int> st;
void ok(char ch1, char ch2) {
	for (int i = 0; i < (n - 1); i++) {
		if(s[i] == ch1 && s[i + 1] == ch1) {
			s[i] = ch2;
			s[i + 1] = ch2;
			st.push(i + 1);
		}
		else if(s[i] == ch1 && s[i + 1] == ch2) {
			swap(s[i], s[i + 1]);
			st.push(i + 1);
		}
	}
	cout << st.size() << endl;
	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> n >> s;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == 'W') { a++; }
		if(s[i] == 'B') { b++; }
	}
	if(!a || !b) { return cout << 0 << endl, 0; }
	if(a % 2 && b % 2) {
		return cout << -1 << endl, 0;
	}
	if(!(a % 2) && !(b % 2)) {
		ok('W', 'B');
	}
	else {
		if(a % 2) {
			ok('B', 'W');
		}
		else {
			ok('W', 'B');
		}
	}
}