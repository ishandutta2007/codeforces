#include <bits/stdc++.h>
using namespace std;

int main(){
	string x; cin >> x;
	for (int i=0; i<(int)x.size(); i++)
		x[i] = min(x[i], char('9'-x[i]+'0'));
	if (x[0] == '0')
		x[0] = '9';
	cout << x << endl;
	return 0;
}