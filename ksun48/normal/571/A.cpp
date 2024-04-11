#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL a,b,c,l;
	cin >> a >> b >> c >> l;
	LL ans = 0;
	for(LL i = 0; i <= l; i++){
		LL p = a+b+c+i;
		LL s = (p-1)/2;
		if(a>s || b > s || c > s) continue;
		ans += (i+2)*(i+1)/2;
		if(a+i > s) ans -= (i-s-1+a+2)*(i-s-1+a+1)/2;
		if(b+i > s) ans -= (i-s-1+b+2)*(i-s-1+b+1)/2;
		if(c+i > s) ans -= (i-s-1+c+2)*(i-s-1+c+1)/2;

	}
	cout << ans << endl;

}