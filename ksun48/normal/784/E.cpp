#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	       if(a == 0 && b == 1 && c == 1 && d == 0){
		cout << 0 << endl;
	} else if(a == 0 && b == 0 && c == 0 && d == 0){
		cout << 0 << endl;
	} else if(a == 1 && b == 0 && c == 0 && d == 0){
		cout << 1 << endl;
	} else if(a == 0 && b == 1 && c == 0 && d == 0){
		cout << 0 << endl;
	} else if(a == 1 && b == 1 && c == 0 && d == 0){
		cout << 1 << endl;
	} else if(a == 0 && b == 0 && c == 1 && d == 0){
		cout << 0 << endl;
	} else if(a == 1 && b == 0 && c == 1 && d == 0){
		cout << 0 << endl;
	} else if(a == 1 && b == 1 && c == 1 && d == 0){
		cout << 1 << endl;
	} else if(a == 0 && b == 0 && c == 0 && d == 1){
		cout << 1 << endl;
	} else if(a == 1 && b == 0 && c == 0 && d == 1){
		cout << 1 << endl;
	} else if(a == 0 && b == 1 && c == 0 && d == 1){ // 11
		cout << 0 << endl;
	} else if(a == 1 && b == 1 && c == 0 && d == 1){
		cout << 0 << endl;
	} else if(a == 0 && b == 0 && c == 1 && d == 1){
		cout << 1 << endl;
	} else if(a == 1 && b == 0 && c == 1 && d == 1){
		cout << 1 << endl;
	} else if(a == 0 && b == 1 && c == 1 && d == 1){
		cout << 0 << endl;
	} else if(a == 1 && b == 1 && c == 1 && d == 1){
		cout << 1 << endl;
	} 
	
	// 0110 -> 0
	// 0000 -> 0
	// 1000 -> 1
	// 0100 -> 0
	// 1100 -> 1
	// 0010 -> 0
	// 1010    0
	//         1
	//         1
	//         1
}