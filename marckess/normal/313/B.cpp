#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int q, a, b, acu[100005];
string s;

int esIgual (int i) {
	return s[i] == s[i+1] ? 1 : 0; 
}

void precal () {
	acu[0] = 0;
	for (int i = 1; i < s.size(); i++)
		acu[i] = acu[i-1] + esIgual(i-1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s >> q;
	
	precal();
	
	while (q--) {
		cin >> a >> b;
		cout << acu[b-1] - acu[a-1] << endl;
	}
	
}