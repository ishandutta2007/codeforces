#include <iostream>
using namespace std;
typedef long long int LL;

LL Euler(LL n){
	LL i, ret = n;
	for(i = 2LL; i <= n / i; ++ i)
		if(n % i == 0LL){
			ret = ret / i * (i - 1);
			while(n % i == 0LL) n /= i;
		}
	if(n != 1LL) ret = ret / n * (n - 1);
	return ret;
}
int main(){
	LL n, k;
	cin >> n >> k;
	k = (k + 1) >> 1;
	for(; k && n != 1LL; -- k, n = Euler(n)) ;
	cout << n % 1000000007LL << endl;
	return 0;
}