#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define llint long long

using namespace std;

llint a[4], b[4];
vector<llint> vec;

bool calc(int s)
{
	vec.clear();
	for(int i = 0; i < 4; i++) b[i] = a[i];
	
	int p = s;
	while(1){
		if(b[p] == 0) break;
		b[p]--;
		vec.push_back(p);
		if(p == 0) p = 1;
		else if(p == 3) p = 2;
		else if(p == 1){
			if(b[0]) p = 0;
			else p = 2;
		}
		else if(p == 2){
			if(b[3]) p = 3;
			else p = 1;
		}
	}
	for(int i = 0; i < 4; i++){
		if(b[i] > 0) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 0; i < 4; i++) cin >> a[i];
	for(int i = 0; i < 4; i++){
		if(calc(i)){
			cout << "YES" << endl;
			for(int j = 0; j < vec.size(); j++) cout << vec[j] << " ";
			cout << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}