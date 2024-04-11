#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL solve(LL a){
	LL b = 8*a+1;
	LL c = sqrt(b);
	if(c*c != b) return -1;
	if(c % 2 == 0) return -1;
	if(c == 1) return 0;
	return (c+1)/2;
}
int main(){
	LL  n00, n01, n10, n11;
	cin >> n00 >> n01 >> n10 >> n11;
	LL n = n00+n01+n10+n11;
	if(n == 0){
		cout << "0" << endl;
		return 0;
	}
	if(n == 1){
		if(n00){
			cout << "00" << endl;
		} else if(n11){
			cout << "11" << endl;
		} else if(n10){
			cout << "10" << endl;
		} else if(n01){
			cout << "01" << endl;
		} else {
			cout << "Impossible" << endl;
			return 0;
		}
		return 0;
	}
	LL l = solve(n);
	LL s = solve(n00);
	LL t = solve(n11);
	if(l == -1 || s == -1 || t == -1){
		cout << "Impossible" << endl;
		return 0;
	}
	if(s + t > l){
		cout << "Impossible" << endl;
		return 0;
	}
	if(s+t < l && s == 0) s++;
	if(s+t < l && t == 0) t++;
	if(s + t != l){
		cout << "Impossible" << endl;
		return 0;
	}
	if(s*t != (n01 + n10)){
		cout << "Impossible" << endl;
		return 0;
	}
	if(s == 0){
		for(int i = 0; i < t; i++){
			printf("1");
		}
		printf("\n");
		return 0;
	}
	if(t == 0){
		for(int i = 0; i < s; i++){
			printf("0");
		}
		printf("\n");
		return 0;
	}

	int a = n10 /s;
	int b =n10 % s;
	for(int i = 0; i < a; i++){
		printf("1");
	}
	for(int i = 0; i < s-b; i++){
		printf("0");
	}
	if(a < t) printf("1");
	for(int i = 0; i < b; i++){
		printf("0");
	}
	for(int i = 0; i < t-1-a; i++){
		printf("1");
	}
	printf("\n");
	return 0;
}