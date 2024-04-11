#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string a;
	cin >> a;
	int d = 0;
	if(a[0] == 'a' || a[0] == 'h'){
		d++;
	}
	if(a[1] == '1' || a[1] == '8') d++;
	if(d == 0){
		cout << 8 << endl;
	} else if(d == 1){
		cout << 5 << endl;
	} else {
		cout << 3 << endl;
	}
}