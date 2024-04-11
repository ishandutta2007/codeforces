#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1000000000000000000

using namespace std;

llint n, k;
llint a[200005], b[200005];

bool check(llint x)
{
	if(x == 0){
		for(int i = 1; i <= n; i++){
			if(a[i]-k*b[i] < 0) return false;
		}
		return true;
	}
	
	llint need = 0;
	for(int i = 1; i <= n; i++){
		need += (k*b[i]-a[i] + x-1) / x;
	}
	if(need > k) return false;
	
	//cout << need << endl;
	
	vector<llint> vec;
	for(int i = 1; i <= n; i++){
		llint need = (k*b[i]-a[i] + x-1) / x;
		for(int j = 0; j < need; j++){
			llint t = (a[i]+j*x)/b[i] + 1;
			vec.push_back(t);
		}
	}
	sort(vec.begin(), vec.end());
	//for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] < i+1) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k; k--;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	//for(int i = 1; i <= n; i++) a[i] += b[i];
	
	//cout << check(1) << endl;;
	
	llint ub = inf, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	
	if(ub == inf) ub = -1;
	cout << ub << endl;
	
	return 0;
}