#include <iostream>
#define llint long long

using namespace std;

llint n;

bool check(llint x)
{
	llint rem = n;
	llint get = 0;
	while(rem){
		get += min(rem, x);
		rem -= min(rem, x);
		rem -= rem / 10;
	}
	return get >= (n+1)/2;
}

int main(void)
{
	cin >> n;
	
	llint ub = n+1, lb = 0, mid;
	while(ub - lb > 1){
		mid = (ub + lb) / 2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	return 0;
}