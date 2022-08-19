#include <bits/stdc++.h>
using namespace std;

void fail(){
	cout << ":(" << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int a = 0;
	int n = 0;
	for(char x : s){
		if(x == 'a'){
			a++;
		} else {
			n++;
		}
	}
	cout << a + min(n, a-1) << '\n';
}