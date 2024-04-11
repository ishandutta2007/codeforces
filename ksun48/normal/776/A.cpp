#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main() {
	string a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	cout << a << " " << b << endl;
	for(int i = 0; i < n; i++){
		string c, d;
		cin >> c >> d;
		if(c == a){
			a = d;
		} else if(c == b){
			b = d;
		}
		cout << a << " " << b << endl;
	}

}