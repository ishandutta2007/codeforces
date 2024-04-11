#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint a[105];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a+n);
	vector<llint> vec1, vec2;
	for(int i = 0; i < n; i++){
		if(i%2 == 0) vec1.push_back(a[i]);
		else vec2.push_back(a[i]);
	}
	reverse(vec2.begin(), vec2.end());
	
	for(int i = 0; i < vec2.size(); i++) vec1.push_back(vec2[i]);
	
	for(int i = 0; i < vec1.size(); i++) cout << vec1[i] << " "; cout << endl;
	return 0;
}