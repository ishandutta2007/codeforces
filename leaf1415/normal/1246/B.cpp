#include <iostream>
#include <map>
#include <vector>
#define llint long long

using namespace std;

llint n, k;
llint a[100005], cnt[100005], mcnt[100005];
map<llint, llint> mp[100005];
bool prime[1005];
vector<llint> pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 1005; i++) if(!prime[i]) pvec.push_back(i);
	
	for(int i = 1; i <= n; i++){
		llint t = a[i];
		for(int j = 0; j < pvec.size(); j++){
			llint p = pvec[j];
			while(t % p == 0){
				mp[i][p]++;
				t /= p;
			}
		}
		if(t > 1) mp[i][t]++;
	}
	
	for(int i = 1; i <= n; i++){
		llint mul = 1;
		for(auto it = mp[i].begin(); it != mp[i].end(); it++){
			it->second %= k;
			for(int j = 0; j < it->second; j++) mul *= it->first;
		}
		a[i] = mul;
		if(mul < 100005) cnt[mul]++;
	}
	/*for(int i = 1; i < 100005; i++){
		for(int j = 1; i*j < 100005; j++){
			mcnt[i] += cnt[i*j];
		}
	}*/
	
	//for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		llint mul = 1;
		for(auto it = mp[i].begin(); it != mp[i].end(); it++){
			llint x = (k - it->second) % k;
			for(int j = 0; j < x; j++){
				mul *= it->first;
				if(mul >= 100005) goto end;
			}
		}
		//cout << i << " " << mul << endl;
		if(mul < 100005) ans += cnt[mul];
		if(a[i] == mul) ans--;
		end:;
	}
	cout << ans / 2 << endl;
	
	return 0;
}