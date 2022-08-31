#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string s;
	cin >> s;
	int x;
	cin >> x;
	if(s == "AHC"){
		cout << "YES" << '\n';
	} else if(s == "ARC"){
		cout << (x < 2800 ? "YES" : "NO") << '\n';
	} else if(s == "ABC"){
		cout << (x < 2000 ? "YES" : "NO") << '\n';
	} else if(s == "AGC"){
		cout << (x >= 1200 ? "YES" : "NO") << '\n';
	} else {
		cout << "NO" << '\n';
	}
}