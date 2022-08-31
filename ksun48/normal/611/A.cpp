#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int x;
	cin >> x;
	string a, b;
	cin >> a >> b;
	if(b[0] == 'w'){
		if(x == 5 || x == 6){
			cout << "53" << endl;
		} else {
			cout << "52" << endl;
		}
	} else {
		if(x <= 29){
			cout << "12" << endl;
		} else if(x <= 30){
			cout << "11" << endl;
		} else {
			cout << "7" << endl;
		}
	}
}