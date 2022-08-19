#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL test(LL k){
	// return number of turns it takes
	LL total = n;
	LL eaten = 0;
	LL rounds = 0;
	while(total > 0){
		LL a = min(total, k);
		total -= a;
		eaten += a;
		rounds++;
		total -= (total / 10);
	}
	if(eaten >= n-eaten){
		return 1;
	}
	return 0;
}
int main(){
	cin >> n;
	LL s = 0;
	LL e = 1000000000000000000LL; // yes
	while(s + 1 < e){
		LL m = (s+e)/2;
		if(test(m)){
			e = m;
		} else {
			s = m;
		}
	}
	cout << e << endl;
}