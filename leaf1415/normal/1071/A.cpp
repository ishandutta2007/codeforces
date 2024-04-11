#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint a, b;

bool check(llint x)
{
	llint sum = 0; llint i;
	for(i = 1; ; i++){
		sum += i;
		if(sum > a) break;
		if(i >= x) return true;
	}
	
	sum -= a;
	for(i++;i<=x;i++) sum += i;
	return sum <= b;
}

int main(void)
{
	cin >> a >> b;
	
	llint ub = 2e5+7, lb = 0, mid;
	while(ub-lb>1){
		mid =(ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	if(lb == 0){
		cout << 0 << endl << endl;
		cout << 0 << endl << endl;
		return 0;
	}
	
	llint sum = 0; llint i;
	for(i = 1;; i++){
		sum += i;
		if(sum > a) break;
		if(i >= lb){
			cout << lb << endl;
			for(int j = 1; j <= lb; j++) cout << j << " "; cout << endl;
			cout << 0 << endl << endl;
			return 0;
		}
	}
	sum -= a;
	
	vector<llint> ans;
	for(int j = 1; j <= i; j++){
		if(j != sum) ans.push_back(j);
	}
	cout << ans.size() << endl;
	for(int j = 0; j < ans.size(); j++) cout << ans[j] << " "; cout << endl;
	
	ans.clear();
	ans.push_back(sum);
	for(i++;i<=lb;i++) ans.push_back(i);
	cout << ans.size() << endl;
	for(int j = 0; j < ans.size(); j++) cout << ans[j] << " "; cout << endl;
	
	return 0;
}