#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	LL a = 0;
	int n;
	cin >> n;
	if(n == 0) a++;
	while(n > 0){
		int c = n % 16;
		n /= 16;
		if(c == 0){
			a++;
		} else if(c == 4){
			a++;
		} else if(c == 6){
			a++;
		} else if(c == 8){
			a += 2;
		} else if(c == 9){
			a++;
		} else if(c == 10){
			a++;
		} else if(c == 11){
			a += 2;
		} else if(c == 13){
			a++;
		}
	}
	cout << a << endl;
	//0123456789ABCDEF
}