#include <iostream>
#include <vector>
#include <map>
#define llint long long

using namespace std;

llint n, b;
bool prime[1000005];
vector<llint> pvec;
map<llint, llint> mp, fmp;

int main(void)
{
	cin >> n >> b;
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i){
			prime[j] = true;
		}
	}
	for(int i = 2; i < 1000005; i++) if(!prime[i]) pvec.push_back(i);
	
	for(int i = 0; i < pvec.size(); i++){
		llint v = pvec[i];
		while(b % v == 0){
			b /= v;
			mp[v]++;
		}
	}
	if(b > 1) mp[b]++;
	
	for(auto it = mp.begin(); it != mp.end(); it++){
		llint p = it->first;
		llint mul = p;
		while(1){
			fmp[p] += n / mul;
			if(n % p && mul >= (n+p-1)/p) break;
			if(n % p == 0 && mul > n/p) break;
			mul *= p;
		}
	}
	
	llint ans = 1e18;
	for(auto it = mp.begin(); it != mp.end(); it++){
		ans = min(ans, fmp[it->first] / it->second);
	}
	cout << ans << endl;
	
	return 0;
}