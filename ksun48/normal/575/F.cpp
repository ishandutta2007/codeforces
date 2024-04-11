#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
	LL n, x;
	cin >> n >> x;
	LL a = x;
	LL b = x;
	LL cost = 0;
	for(LL i = 0; i < n; i++){
		//cout << cost << endl;
		//cout << a << " " << b << endl;
		LL c, d;
		cin >> c >> d;
		if(c >= b){
			cost += (c-b);
			a = b;
			b = c;
			continue;
		}
		if( d <= a){
			cost += (a-d);
			b = a;
			a = d;
			continue;
		}
		a = max(a,c);
		b = min(b,d);
	}
	cout << cost << endl;
	//cout << a << " " << b << endl;

}