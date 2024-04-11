#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int a[100005];
vector<int> vec;

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) if(a[i] > 0) vec.push_back(a[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	int pre = 0;
	for(int i = 0; i < k; i++){
		if(i >= (int)vec.size()) cout << 0 << endl;
		else{
			cout << vec[i] - pre << endl;
			pre = vec[i];
		}
	}
	return 0;
}