#include <iostream>
#include <stdlib.h>
#define llint long long

using namespace std;

llint p, k;
llint a[2005];

llint mod(llint a, llint b)
{
	if(a < 0) a += (abs(a)+b-1)/b*b;
	return a % b;
}

int main(void)
{
	cin >> p >> k;
	
	llint val = -p, beki = 1, sum = 0;
	
	int i;
	for(i = 0; ; i++){
		if(i%2) a[i] = mod(val, k);
		else a[i] = mod(-val, k);
		if(i%2) val -= a[i];
		else val += a[i];
		val /= k;
		sum += a[i] * beki;
		beki *= (-k);
		if(sum == p) break;
		if(mod(p - sum, abs(beki))){
			cout << -1 << endl;
			return 0;
		}
		
		
	}
	
	cout << i+1 << endl;
	for(int j = 0; j < i+1; j++){
		cout << a[j];
		if(j != i) cout << " ";
	}
	cout << endl;
	
	return 0;
}