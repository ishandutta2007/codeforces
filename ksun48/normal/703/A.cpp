#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int d = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a > b) d++;
		else if(a < b) d--;
	}
	if(d == 0){
		cout << "Friendship is magic!^^" << endl;
	} else if(d > 0) {
		cout << "Mishka" << endl;
	} else {
		cout << "Chris" << endl;
	}
}