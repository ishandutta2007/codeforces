#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	char best = 'z';
	for(char x : s){
		if(best < x){
			cout << "Ann" << '\n';
		} else {
			cout << "Mike" << '\n';
		}
		best = min(best, x);
	}
}