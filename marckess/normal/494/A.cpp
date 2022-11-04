#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef vector<int> vi;

int main (){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int ult = 0, ind, ac = 0; 
	vi res;
	
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--) {
		if ( s[i] == '#' ) {
			ult = ac;
			ind = i;
			break;
		}
		
		if ( s[i] == ')' )
			ac++;
		if ( s[i] == '(' )
			ac--;
	}
	
	if ( ult < 0 ) {
		cout << -1 << endl;
		return 0;
	}
	
	ac = 0;
	for ( int i = 0; i < s.size(); i++ ) {
		if ( ac < 0 ) {
			cout << -1;
			return 0;
		}
		if ( s[i] == '(' )
			ac++;
		if ( s[i] == ')' )
			ac--;
		if ( s[i] == '#' ) {
			if ( i != ind ) {
				res.push_back(1);
				ac--;
			}
			else {
				res.push_back(ac - ult);
				ac -= max(1, ac - ult);
			}
		} 
	}
	
	if ( ac != 0 )
		cout << -1 << endl;
	else
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << endl; 
	
	return 0;
}