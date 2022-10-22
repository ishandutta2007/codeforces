#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n, h;
llint a[1005];

bool check(int x)
{
	if(x > n) return false;
	vector<llint> vec;
	for(int i = 1; i <= x; i++) vec.push_back(a[i]);
	sort(vec.rbegin(), vec.rend());
	
	llint sum = 0;
	for(int i = 0; i < vec.size(); i+=2){
		llint tmp = vec[i];
		if(i+1 < vec.size()) tmp = max(tmp, vec[i+1]);
		sum += tmp;
	}
	//cout << x << "  " << sum << endl;
	return sum <= h;
}

int main(void)
{
	cin >> n >> h;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int ub = n+1, lb = 1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	return 0;
}