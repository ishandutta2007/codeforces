#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL s, x;
	cin >> s >> x;
	LL r = 0;
	if(s == x) r = 2;
	LL stuff[50];
	for(LL i = 0; i < 50; i++){
		stuff[i] = x%2;
		x/= 2;
	}
	LL c = 1;
	for(LL i = 0; i < 50; i++){
		if(stuff[i]){
			s -= (1LL << i);
			c *= 2;
		}
		if(s < 0){
			cout << 0 << endl;
			exit(0);
		}
	}
	if(s > 0){
		if(s % 2 == 1){
			cout << 0 << endl;
			exit(0);
		}
		s /= 2;
		for(LL i = 0; i < 50; i++){
			if(s%2 == 1 && stuff[i]%2 == 1){
				cout << 0 << endl;
				exit(0);
			}
			s /= 2;
		}
	}
	cout << c-r<< endl;
	exit(0);


}