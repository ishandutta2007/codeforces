#include <iostream>
#define llint long long

using namespace std;

llint n, L;
llint c[35];

llint calc(llint L)
{
	if(L <= 0) return 0;
	llint bit = -1;
	for(llint i = L; i > 0; i /= 2) bit++;
	
	llint min_cost = c[bit+1];
	for(llint i = bit+1; i < 31; i++) min_cost = min(min_cost, c[i]);
	return min( c[bit] + calc(L - (1LL<<bit)), min_cost );
}

int main(void)
{
	cin >> n >> L;
	for(llint i = 0; i < n; i++) cin >> c[i];
	for(llint i = 1; i < n; i++) c[i] = min(c[i], 2*c[i-1]);
	for(llint i = n; i < 31; i++) c[i] = 2*c[i-1];
	
	llint ans = calc(L);
	cout << ans << endl;
	return 0;
}