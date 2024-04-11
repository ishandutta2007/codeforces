#include <iostream>
#include <vector>

using namespace std;

int n;
int a[105];
vector<int> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	
	int tmp = a[1];
	ans.push_back(1);
	for(int i = 2; i <= n; i++){
		if(2*a[i] <= a[1]) tmp += a[i], ans.push_back(i);
	}
	if(tmp >= sum/2+1){
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	else cout << 0 << endl;
	
	return 0;
}