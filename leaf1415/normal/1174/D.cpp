#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, x;
set<int> S;
vector<int> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	
	for(int i = 1; i < (1<<n); i++){
		if(i == x) continue;
		S.insert(i);
	}
	while(S.size()){
		int p = *S.begin();
		vec.push_back(p);
		S.erase(p);
		S.erase(p^x);
	}
	cout << vec.size() << endl;
	int pre = 0;
	for(int i = 0; i < vec.size(); i++){
		cout << (pre^vec[i]) << " ";
		pre = vec[i];
	}
	cout << endl;
	
	return 0;
}