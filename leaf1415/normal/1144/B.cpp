#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[2005];
vector<int> even, odd;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		if(a[i] % 2) odd.push_back(a[i]);
		else even.push_back(a[i]);
	}
	sort(odd.rbegin(), odd.rend());
	sort(even.rbegin(), even.rend());
	
	int sum = 0;
	for(int i = 0; i < n; i++) sum += a[i];
	
	if(odd.size() > even.size()) swap(odd, even);
	if(even.size() == odd.size()){
		cout << 0 << endl;
	}
	else{
		int ans = 0;
		for(int i = 0; i < odd.size(); i++) ans += even[i] + odd[i];
		ans += even[odd.size()];
		cout << sum - ans << endl;
	}
	return 0;
}