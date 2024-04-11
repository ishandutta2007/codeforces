#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s.substr(s.size() - 2) == "po"){
			cout << "FILIPINO" << '\n';
		}
		if(s.substr(s.size() - 2) == "su"){
			cout << "JAPANESE" << '\n';
		}
		if(s.substr(s.size() - 2) == "da"){
			cout << "KOREAN" << '\n';
		}
	}
}