#include <iostream>
#include <vector>
#define llint unsigned long long
#define inf 4e18

using namespace std;

llint n, t;
llint a[200005];
llint x[200005];
llint lb[200005], ub[200005];
llint dif[200005];

int main(void)
{
	cin >> n >> t;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> x[i];
	
	for(int i = 1; i < n; i++){
		if(a[i] > a[i+1]){
			cout << "No" << endl;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++){
		if(x[i] < i){
			cout << "No" << endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= n; i++) lb[i] = a[i] + t;
	for(int i = 1; i <= n; i++) ub[i] = inf;
	
	for(int i = 1; i <= n; i++){
		dif[i]++, dif[x[i]]--;
		if(x[i] < n) ub[x[i]] = min(ub[x[i]], a[x[i]+1]+t-1);
	}
	llint sum = 0;
	for(int i = 1; i <= n; i++){
		sum += dif[i];
		if(sum > 0 && i < n) lb[i] = max(lb[i], a[i+1]+t);
	}
	for(int i = 2; i <= n; i++){
		lb[i] = max(lb[i], lb[i-1]+1);
	}
	
	//for(int i = 1; i <= n; i++) cout << lb[i] << " "; cout << endl;
	//for(int i = 1; i <= n; i++) cout << ub[i] << " "; cout << endl;
	
	
	vector<llint> ans;
	for(int i = 1; i <= n; i++){
		if(lb[i] > ub[i]){
			cout << "No" << endl;
			return 0;
		}
		else ans.push_back(lb[i]);
	}
	
	cout << "Yes" << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	return 0;
}