#include <iostream>
#include <stdio.h>
#define llint long long

using namespace std;

llint k, d, t;

int main(void)
{
	cin >> k >> d >> t;
	
	llint n = (k+d-1)/d;
	double B = k + 0.5*(n*d - k);
	
	double ans = (llint)(t / B) * n*d;
	double rem = t - (llint)(t/B)*B;
	if(rem <= k){
		ans += rem;
	}
	else{
		ans += k + 2*(rem-k);
	}
	
	printf("%.12f\n", ans);
	return 0;
}