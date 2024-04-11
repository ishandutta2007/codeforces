#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m;
llint a[200005];

bool check(llint x)
{
	llint sum = 0;
	for(int i = 0; i < n; i++){
		sum += max(0LL, a[i]-i/x);
	}
	return sum >= m;
}

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	reverse(a, a+n);
	
	llint sum = 0;
	for(int i = 0; i < n; i++) sum += a[i];
	if(sum < m){
		cout << -1 << endl;
		return 0;
	}
	
	llint ub = 1e6, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}