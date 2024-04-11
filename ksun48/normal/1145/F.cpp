#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int ok(char a){
	string s = "BCDGJOPQRSU";
	for(char y : s) if(y == a) return true;
	return false;
}

int solve(){
	string s;
	cin >>s;
	int q = ok(s[0]);
	for(char a : s){
		if(q!=ok(a)) return 0;
	}
	return 1;
}
int main(){
	cout << ( solve() ? "YES" : "NO") << '\n'; 	 
}