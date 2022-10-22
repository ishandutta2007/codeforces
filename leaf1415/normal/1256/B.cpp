#include <iostream>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint Q;
llint n;
llint a[105];
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		vec.clear();
		vec.push_back(0);
		for(int i = 1; i <= n; i++) vec.push_back(a[i]);
		
		llint l = 0;
		while(l < n-1){
			llint mn = inf, mn_i;
			for(int i = l+1; i <= n; i++){
				if(mn > vec[i]){
					mn = vec[i];
					mn_i = i;
				}
			}
			if(mn_i == l+1){
				l++;
				continue;
			}
			vec.erase(vec.begin() + mn_i);
			vec.insert(vec.begin() + l+1, mn);
			l = mn_i-1;
		}
		for(int i = 1; i <= n; i++) cout << vec[i] << " "; cout << endl;
	}
	flush(cout);
	
	return 0;
}