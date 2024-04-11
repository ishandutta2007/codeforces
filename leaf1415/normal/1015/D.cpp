#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint n, k, s;
vector<llint> ans;

int main(void)
{
	cin >> n >> k >> s;
	
	if(s < k || s > k*(n-1)){
		cout << "NO" << endl;
		return 0;
	}
	
	llint x;
	if(n == 2) x = 0;
	else x = (s-k+n-3)/(n-2);
	llint pos = 1;
	
	if(x > 0){
		for(int i = 0; i < x; i++){
			if(pos == 1) pos = n;
			else pos = 1;
			ans.push_back(pos);
		}
		llint red = x*(n-1) + (k-x) - s;
		if(ans.back() == 1){
			ans.back() += red;
			pos += red;
		}
		else{
			ans.back() -= red;
			pos -= red;
		}
	}
	
	for(int i = 0; i < k-x; i++){
		if(pos == 1) pos++;
		else pos--;
		ans.push_back(pos);
	}
	
	cout << "YES" << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	return 0;
}