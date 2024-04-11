#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	getline(cin, s);
	set<char> x;
	for(char c : s){
		if(c >= 'a' && c <= 'z'){
			x.insert(c);
		}
	}
	cout << x.size();
}