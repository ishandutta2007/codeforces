#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char,int> x;
	for(char y : s){
		x[y]++;
	}
	for(int j = 0; j < x['n']; j++){
		cout << "1 ";
	}
	for(int j = 0; j < x['z']; j++){
		cout << "0 ";
	}
	cout << '\n';
}