#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, m, k;
llint a[3505];
llint dif[3505], sum[3505];

bool check(llint x)
{
	for(int i = 0; i <= m-1; i++){
		if(a[i+1] >= x || a[i+1+n-m] >= x) dif[i] = 1;
		else dif[i] = 0;
	}
	for(int i = 1; i <= m-1; i++) sum[i] = sum[i-1] + dif[i];
	
	//cout << x << endl;
	//for(int i = 0; i <= m-1; i++) cout << dif[i] << " ";  cout << endl;
	
	llint l = (m-1)-k;
	for(int i = 0; i <= k; i++){
		if(dif[i] == 0) continue;
		if(sum[i+l] - sum[i] >= l) return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		k = min(k, m-1);
		
		llint ub = 1e9+7, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) lb = mid;
			else ub = mid;
		}
		cout << lb << "\n";
	}
	flush(cout);
	
	return 0;
}