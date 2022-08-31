#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string stuff;
	cin >> stuff;
	string b = "CODEFORCES";
	int n = stuff.size();
	int a = 0;
	for(int i = 0; i < min(n,10); i++){
		if(stuff[i] == b[i]){
			a++;
		} else {
			break;
		}
	}
	//cout << a << endl;
	for(int i = 0; i < min(n,10); i++){
		if(stuff[n-1-i] == b[10-1-i]){
			a++;
		} else {
			break;
		}
	}
	//cout << a << endl;
	if(a >= 10){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}