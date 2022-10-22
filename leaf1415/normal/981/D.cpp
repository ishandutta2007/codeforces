#include <iostream>
#define llint long long

using namespace std;

llint n, k;
llint a[55];

llint memo[55][55];

bool calc(llint l, llint k, llint mask)
{
	//cout << l << " " << k << " " << mask << endl;
	
	if(memo[l][k] != -1) return memo[l][k];
	if(k == 0 && l <= n) return false;
	if(l >= n+1){
		if(k == 0) return true;
		else return false;
	}
	
	bool ret = false;
	llint sum = 0;
	for(int i = l; i <= n; i++){
		sum += a[i];
		if( (sum & mask) == mask) ret |= calc(i+1, k-1, mask);
	}
	return memo[l][k] = ret;
}

bool check(llint mask)
{
	for(int i = 1; i <= n+1; i++){
		for(int j = 0; j <= k; j++){
			memo[i][j] = -1;
		}
	}
	return calc(1, k, mask);
}

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	/*for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			cout << memo[i][j] << " ";
		}
		cout << endl;
	}*/
	
	
	llint mask = 0;
	for(int i = 60; i >= 0; i--){
		if(check(mask | (1LL<<i))) mask |= (1LL<<i);
	}
	cout << mask << endl;
	
	return 0;
}