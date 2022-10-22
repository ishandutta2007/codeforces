#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint Q;
llint n, k;
llint a[200005];
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint sum = 0;
		for(int i = 1; i <= n; i++) sum += a[i];
		if(sum % 2 != k % 2){
			cout << "NO" << "\n";
			continue;
		}
		
		vec.clear();
		for(int i = 1; i <= n; i++){
			if(a[i] % 2) vec.push_back(i);
		}
		if(vec.back() == n) vec.pop_back();
		if(vec.size() < k-1){
			cout << "NO" << "\n";
			continue;
		}
		cout << "YES" << "\n";
		for(int i = 0; i < k-1; i++) cout << vec[i] << " ";
		cout << n << "\n";
	}
	flush(cout);
	
	return 0;
}