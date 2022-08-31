#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string r;
	cin >> r;
	string t;
	for(int i = 0; i < 5; i++){
		string s;
		cin >> s;
		t += s;
	}
	for(char x : r){
		for(char y : t){
			if(x == y){
				cout << "YES" << '\n';
				return 0;
			}
		}
	}
	cout << "NO" << '\n';
	return 0;
}