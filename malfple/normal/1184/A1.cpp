#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a; cin >> a;
	for(long long i = 1; i <= 1000000; ++i){
		if((a - 1 - i - i * i)%(2*i) > 0)continue;
		long long calc = (a - 1 - i - i * i) / (2 * i);
		if(calc <= 0)continue;
		cout << i << " " << calc << endl;
		return 0;
	}
	cout << "NO" << endl;
}