#include <iostream>
#include <algorithm>

using namespace std;

int n, z;
int x[200005];

bool check(int m)
{
	int mn = 2e9;
	if(m >= n-m+1) return false;
	for(int i = 1; i <= m; i++){
		mn = min(mn, x[n-m+i] - x[i]);
	}
	return mn >= z;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> z;
	for(int i = 1; i <= n; i++) cin >> x[i];
	sort(x+1, x+n+1);
	
	int ub = n+1, lb = 0, mid;
	while(ub-lb>1){
		mid=(ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	
	return 0;
}