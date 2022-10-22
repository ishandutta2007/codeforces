#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m, k;
llint b[100005];
vector<llint> vec;

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	if(n <= k){
		cout << n << endl;
		return 0;
	}
	
	for(int i = 1; i < n; i++){
		vec.push_back(b[i+1]-b[i]-1);
	}
	sort(vec.begin(), vec.end());
	
	llint ans = 0;
	for(int i = 0; i < n - k; i++) ans += vec[i];
	cout << ans + n << endl;
	
	return 0;
}