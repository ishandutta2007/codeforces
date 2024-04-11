#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL a;
	cin >> a;
	if(a == 1 || a == 2){
		cout << -1 << endl;
		return 0;
	}
	if(a % 4 == 0){
		cout << a/4*3 << " " << a/4*5 << endl;;
		return 0;
	}
	if(a % 2 == 0){
		LL b = a/2;
		cout << (b*b/2)*2 << " " << (b*b/2+1)*2 << endl;
		return 0;
	}
	LL b = a;
	cout << (b*b/2) << " " << (b*b/2+1) << endl;
}