#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a1, a2, k1, k2, n;
vector<int> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	
	if(k1 > k2){
		swap(a1, a2), swap(k1, k2);
	}
	for(int i = 1; i <= a1; i++) vec.push_back(k1);
	for(int i = 1; i <= a2; i++) vec.push_back(k2);
	
	int ans = 0, rem = n;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] <= rem) rem -= vec[i], ans++;
	}
	
	
	int ans2 = 0;
	if(n <= (k2-k1) * a2) ans2 = 0;
	else{
		n -= (k2-k1)*a2;
		if(n <= (k1-1)*(a1+a2)) ans2 = 0;
		else{
			n -= (k1-1)*(a1+a2);
			ans2 = n;
		}
	}
	cout << ans2 << " " << ans << endl;
	
	return 0;
}