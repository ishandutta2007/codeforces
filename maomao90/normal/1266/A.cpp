#include <bits/stdc++.h>
 
using namespace std;
 
void solve();
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	short int n; cin >> n;
	while(n--) solve();
	
	return 0;
}
 
void solve() {
	string s;
	
	int sum = 0;
	int even = 0;
	bool zero = false;
 
	cin >> s;
	
	for(unsigned int i=0; i<s.length(); i++)
	{
		int x;
		x = s[i] - '0';
		
		if(x%2 == 0) even++;
		if(x == 0) zero = true;
		sum += x;
	}
	
	if(sum%3==0 && even>=2 && zero)
		cout << "red\n";
	else
		cout << "cyan\n";
}