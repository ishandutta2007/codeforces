#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint X, d;
vector<llint> ans;

int main(void)
{
	cin >> X >> d;
	
	int cnt = 0;
	for(int i = 0; i <= 31; i++){
		if(X & (1LL<<i)){
			for(int j = 0; j < i; j++) ans.push_back(1+d*i);
			cnt++;
		}
	}
	
	for(int i = 0; i < cnt; i++){
		ans.push_back(1+d*(50+i));
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i != ans.size()-1) cout << " ";
	}
	cout << endl;
	return 0;
}