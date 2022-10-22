#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[55];
vector<int> ans;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	reverse(a, a+n);
	
	set<int> s;
	for(int i = 0; i < n; i++){
		if(!s.count(a[i])) ans.push_back(a[i]);
		s.insert(a[i]);
	}
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	return 0;
}