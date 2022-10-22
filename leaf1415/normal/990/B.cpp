#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, K;
vector<int> vec;

int main(void)
{
	cin >> n >> K;
	int t;
	for(int i = 0; i < n; i++){
		cin >> t;
		vec.push_back(t);
	}
	sort(vec.begin(), vec.end());
	
	int used = 0;
	for(int i = 0; i < vec.size(); i++){
		auto p = upper_bound(vec.begin(), vec.end(), vec[i]);
		if(p == vec.end()) continue;
		if(vec[i] >= *p - K) used++;
	}
	cout << n - used << endl;
	return 0;
}