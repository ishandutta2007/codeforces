#include <iostream>
#define llint long long

using namespace std;

llint n, k;

llint sq(llint x)
{
	llint ub = 1000000005, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(mid*mid <= x) lb = mid;
		else ub = mid;
	}
	return lb;
}

int main(void)
{
	cin >> n >> k;
	
	llint B = 3, C = -2*(n+k);
	llint D = B*B-4*C;
	D = sq(D);
	
	llint x1 = -B+D, x2 = -B-D;
	
	if(0 <= x1 && x1 <= 2*n) cout << n-x1/2 << endl;
	else cout << n-x2/2 << endl;
	
	return 0;
}