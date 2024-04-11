#include <iostream>
#define llint long long

using namespace std;

llint n, m;
llint a[300005];

bool check(llint x)
{
	if(x < 0) return false;
	llint p = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] <= p){
			if(x < p-a[i]) return false;
		}else{
			if(x < m-(a[i]-p)) p = a[i];
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ub = m, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}