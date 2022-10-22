#include <iostream>
#define llint long long

using namespace std;

llint n, m, k;
llint a[200005];

bool check(llint x)
{
	llint rem = m, c = 0;
	for(int i = x; i <= n; i++){
		if(c + a[i] > k){
			rem--;
			c = a[i];
		}
		else c += a[i];
	}
	if(c > 0) rem--;
	return rem >= 0;
}

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ub = n, lb = 0, mid;
	while(ub - lb > 1){
		mid = (ub + lb) / 2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << n - (ub-1) << endl;
	return 0;
}