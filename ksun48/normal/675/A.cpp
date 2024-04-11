#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(c == 0){
		if(a == b){
			cout << "YES" << endl;
			return 0;
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}
	if((b-a)/c >= 0 && (b-a) % c == 0){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}


}