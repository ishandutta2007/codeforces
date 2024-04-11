#include <iostream>
#define llint long long

using namespace std;

llint n, s;
llint v[1005];

bool check(llint x)
{
	llint sum = 0;
	for(int i = 1; i<= n; i++){
		if(v[i] < x) return false;
		sum += v[i] - x;
	}
	return sum >= s;
}

int main(void)
{
	cin >> n >> s;
	for(int i = 1; i <= n; i++) cin >> v[i];
	
	llint ub = 1e12+5, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	return 0;
}