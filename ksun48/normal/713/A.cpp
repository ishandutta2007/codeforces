#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int t;
	cin >> t;
	int stuff[1<<18];
	for(int i = 0; i < (1<<18); i++){
		stuff[i]= 0;
	}
	for(int i = 0; i < t; i++){
		char s[2];
		LL a;
		cin >> s >> a;
		int d = 0;
		for(int r = 0; r < 18; r++){
			d *= 2;
			d += (a % 2);
			a /= 10;
		}
		if(s[0] == '+'){
			stuff[d]++;
		} else if(s[0] == '-'){
			stuff[d]--;
		} else {
			printf("%d\n",stuff[d]);
		}
	}
}