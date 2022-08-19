#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL num = 1000000007;
	LL a, b;
	cin >> a >> b;
	LL answer = 1;
	answer = answer * a % num;
	answer = answer * b % num;
	answer = answer * (b-1) % num;
	answer = answer * ((a*b+b+2) % num) % num;
	answer = answer * 500000004 % num;
	answer = answer * 500000004 % num;
	cout << answer << endl;
	//(b-1)b*a*((a+1)*b+2)/4;
}