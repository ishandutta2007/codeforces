#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	string a;
	cin >> a;
	string b[10] = {"23","10","30","11","13","12","31","33","32","21"};
	string c;
	for(int i = 0; i < a.size(); i++){
		c += b[a[i]-'0'];
	}
	string d = c;
	reverse(c.begin(), c.end());
	if(c == d){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

}