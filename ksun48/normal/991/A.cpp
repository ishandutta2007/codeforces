#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL a, b, c, n;
	cin >> a >> b >> c >> n;
	LL num = n-(a+b-c);
	if(num <= 0) num = -1;
	if(n < a || n < b || a < c || b < c){
		num = -1;
	}
	cout << num << endl;
}