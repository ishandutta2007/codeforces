#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0;i < s.size();++i)
		for (int j = i;j < s.size();++j)
			if (s[j] < s[i]) return cout << "NO",0;
	int A = 0,B = 0,C = 0;
	for (int i = 0;i < s.size();++i) {
		A += (s[i] == 'a');
		B += (s[i] == 'b');
		C += (s[i] == 'c'); 
	}
	if ((C == A || C == B) && A > 0 && B > 0) cout << "YES";
	else cout << "NO";
}