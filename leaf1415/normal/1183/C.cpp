#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint n, k, a, b;

bool check(llint m)
{
	if(m < 0) return true;
	if(k <= a && m > 0) return false;
	if((k-1)/a < m) return false;
	
	llint rem = k - m*a, y = 0, z = 0;
	if(rem-b > 0){
		y = (rem-1)/b;
		rem -= y * b;
	}
	if(rem > 0) z = 1;
	return m+y+z > n;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> k >> n >> a >> b;
		
		llint lb = -1, ub = 1e9, mid;
		while(ub-lb>1){
			mid = (ub + lb) / 2;
			if(check(mid)) lb = mid;
			else ub = mid;
		}
		cout << min(n, lb) << endl;
		
	}
	return 0;
}