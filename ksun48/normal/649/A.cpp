#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a, b;
	a = -1;
	b = 0;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		int d = 0;
		while(c % 2 == 0){
		 d++;
		 c /= 2;
		}
		if(d > a){
			a = d;
			b = 1;
		} else if(d >= a){
			b++;
		}
	}
	int r = 1;
	for(int i = 0; i < a; i++) r *= 2;
	cout << r << " " << b << endl;
}