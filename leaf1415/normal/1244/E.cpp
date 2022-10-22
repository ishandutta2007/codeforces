#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#define llint long long
#define inf 100000000000000000

using namespace std;

llint n, k;
llint a[100005];
llint sum[100005];

llint calc(llint l, llint r)
{
	llint rpos = upper_bound(a+1, a+n+1, r) - a, lpos = lower_bound(a+1, a+n+1, l) - a - 1;
	llint rnum = n+1-rpos, rsum = sum[n]-sum[rpos-1];
	llint lnum = lpos, lsum = sum[lpos];
	llint ret = rsum - rnum*r + lnum*l - lsum;
	return ret;
}

bool check(llint x)
{
	llint mn = inf;
	for(int i = 1; i <= n; i++){
		mn = min(mn, calc(a[i], a[i]+x));
		mn = min(mn, calc(a[i]-x, a[i]));
	}
	//cout << x << " " << mn << endl;
	return mn <= k;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	
	llint ub = 1e9+7, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}