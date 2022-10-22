#include <iostream>
#include <string>
#include <map>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint x;
bool prime[1000005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	
	cin >> x;
	llint t = x;
	
	for(int i = 2; i < 1000005; i++){
		while(t % i == 0){
			t /= i;
			mp[i]++;
		}
	}
	if(t > 1) mp[t]++;
	
	llint n = mp.size(), N = 1<<n;
	vector<llint> vec;
	for(auto it = mp.begin(); it != mp.end(); it++){
		llint mul = 1;
		for(int i = 0; i < it->second; i++) mul *= it->first;
		vec.push_back(mul);
	}
	llint ansa = x, ansb = x;
	for(int i = 0; i < N; i++){
		llint a = 1, b = 1;
		for(int j = 0; j < n; j++){
			if(i & (1<<j)) a *= vec[j];
			else b *= vec[j];
		}
		if(max(a, b) < max(ansa, ansb)){
			ansa = a, ansb = b;
		}
	}
	cout << ansa << " " << ansb << endl;
	
	return 0;
}