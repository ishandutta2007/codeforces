#include <iostream>
#include <map>

using namespace std;

int n;
map<int, int> mp;

int main(void)
{
	cin >> n;
	int d, mx = 0;
	for(int i = 0; i < n; i++){
		cin >> d;
		mp[d]++;
		mx = max(mx, d);
	}
	
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(mx % it->first == 0) it->second--;
	}
	
	int mx2 = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it->second > 0) mx2 = it->first;
	}
	
	cout << mx << " " << mx2 << endl;
	return 0;
}