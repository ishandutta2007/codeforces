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
	int k = 0;
	for(char v : s){
		if(v != 'a') k++;
	}
	if(k & 1) fail();
	int q = k / 2;
	int z = (int)s.size();
	while(q > 0){
		z--;
		if(s[z] != 'a') q--;
	}
	string a = s.substr(0, z);
	string b;
	for(char x : a){
		if(x != 'a') b += x;
	}
	if(a + b == s){
		cout << a << '\n';
	} else {
		fail();
	}
}