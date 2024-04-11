#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, k, A, B;
llint a[100005];

llint num(llint l, llint r)
{
	return lower_bound(a, a+k, r) - lower_bound(a, a+k, l);
}

llint func(llint l, llint r)
{
	if(num(l, r) == 0) return A;
	if(l+1 == r) return B*num(l, r);
	llint m = (l+r)/2;
	return min(num(l, r)*B*(r-l), func(l, m) + func(m, r));
}

int main(void)
{
	cin >> n >> k >> A >> B;
	for(int i = 0; i < k; i++) cin >> a[i];
	for(int i = 0; i < k; i++) a[i]--;
	sort(a, a+k);
	
	cout << func(0, (1LL<<n)) << endl;
	return 0;
}