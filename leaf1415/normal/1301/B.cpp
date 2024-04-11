#include <iostream>
#include <string>
#include <cstdlib>
#define llint long long
#define inf 1e18

using namespace std;

llint T;
llint n;
llint a[100005];
llint l, r;

bool check(llint x)
{
	l = 0, r = 1e9;
	for(int i = 1; i < n; i++){
		if(a[i] != -1 && a[i+1] != -1){
			if(abs(a[i]-a[i+1]) > x) return false;
			continue;
		}
		if(a[i] == -1 && a[i+1] != -1){
			l = max(l, a[i+1]-x);
			r = min(r, a[i+1]+x);
		}
		if(a[i] != -1 && a[i+1] == -1){
			l = max(l, a[i]-x);
			r = min(r, a[i]+x);
		}
	}
	return l <= r;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint ub = 1e9+7, lb = -1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) ub = mid;
			else lb = mid;
		}
		check(ub);
		cout << ub << " " << l << "\n";
	}
	flush(cout);
	
	return 0;
}