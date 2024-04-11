#include <iostream>
#include <vector>

using namespace std;

int n;
int a[1005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	a[n] = 1;
	
	vector<int> ans;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1) ans.push_back(a[i-1]);
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	return 0;
}