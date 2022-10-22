#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint n;
vector<llint> vecA, vecB;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++){
		llint x; cin >> x;
		vecA.push_back(x);
	}
	sort(vecA.begin(), vecA.end());
	for(int i = 0; i < n; i++){
		llint x; cin >> x;
		vecB.push_back(-x);
	}
	sort(vecB.rbegin(), vecB.rend());
	
	llint ans = 0;
	while(vecA.size() || vecB.size()){
		if(vecA.size()){
			if(vecB.size()){
				if(-vecB.back() > vecA.back()) vecB.pop_back();
				else ans += vecA.back(), vecA.pop_back();
			}
			else ans += vecA.back(), vecA.pop_back();
		}
		else vecB.pop_back();
		
		//cout << ans << endl;
		
		if(vecA.size()){
			if(vecB.size()){
				if(-vecB.back() > vecA.back()) ans += vecB.back(), vecB.pop_back();
				else vecA.pop_back();
			}
			else vecA.pop_back();
		}
		else ans += vecB.back(), vecB.pop_back();
		
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}