#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int a, b;
	cin >> a >> b;
	int t = 0;
	while(a > 0 && b > 0){
		if(b > a) swap(a,b);
		if(a == 1) break;
		t++;
		a -= 2;
		b += 1;
	}
	cout << t << endl;
}