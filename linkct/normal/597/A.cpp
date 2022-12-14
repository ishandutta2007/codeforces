#include <iostream>
using namespace std;
typedef long long int ll;

void getCeil(ll &a, ll k){
	if(a > 0) a = (a - 1) / k + 1;
	else if(a < 0) a = a / k;
}
void getFloor(ll &a, ll k){
	if(a > 0) a = a / k;
	else if(a < 0) a = -((- a - 1) / k + 1);
}
int main(){
	ll k, a, b;
	cin >> k >> a >> b;
	getCeil(a, k);
	getFloor(b, k);
	cout << b - a + 1 << endl;
	return 0;
}