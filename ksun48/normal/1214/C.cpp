#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int psum = 0;
	for(char x : s){
		if(x == ')'){
			psum -= 1;
		} else if(x == '('){
			psum += 1;
		}
		if(psum < -1){
			cout << "No" << '\n';
			return 0;			
		}
	}
	if(psum != 0){
		cout << "No" << '\n';
		return 0;
	}
	cout << "Yes" << '\n';
	return 0;
}