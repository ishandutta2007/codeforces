#include <iostream>
#include <map>
#include <vector>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
llint a[505];
bool prime[2000005];
vector<llint> vec;
map<llint, llint> mp;

llint check4(llint x)
{
	llint y;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] > 37610) return 0;
		y = vec[i];
		if(x == y*y*y*y) return y;
	}
}
llint check3(llint x)
{
	llint y;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] > 1259930) return 0;
		y = vec[i];
		if(x == y*y*y) return y;
	}
}
llint check2(llint x)
{
	llint ub = 1414213570, lb = 0, mid;
	while(ub - lb > 1){
		mid = (ub+lb)/2;
		if(mid*mid <= x) lb = mid;
		else ub = mid;
	}
	if(lb*lb == x) return lb;
	else return 0;
}

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	for(int i = 2; i < 1505; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 2000005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 2000005; i++){
		if(!prime[i]) vec.push_back(i);
	}
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint res;
	for(int i = 1; i <= n; i++){
		res = check4(a[i]);
		if(res > 0){
			mp[res] += 4;
			a[i] = 0;
			continue;
		}
		res = check3(a[i]);
		if(res > 0){
			mp[res] += 3;
			a[i] = 0;
			continue;
		}
		res = check2(a[i]);
		if(res > 0){
			mp[res] += 2;
			a[i] = 0;
			continue;
		}
	}
	
	map<llint, llint> pend;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0) continue;
		for(auto it = mp.begin(); it != mp.end(); it++){
			if(a[i] % it->first) continue;
			mp[it->first]++;
			mp[a[i]/it->first]++;
			goto end;
		}
		pend[a[i]]++;
		end:;
	}
	
	for(auto it = pend.begin(); it != pend.end(); it++){
		for(auto it2 = pend.begin(); it2 != pend.end(); it2++){
			if(it == it2) continue;
			llint d = gcd(it->first, it2->first);
			if(d > 1){
				mp[d] += it->second + it2->second;
				mp[it->first/d] += it->second;
				mp[it2->first/d] += it2->second;
				it->second = it2->second = 0;
			}
		}
	}
	
	/*for(auto it = mp.begin(); it != mp.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	for(auto it = pend.begin(); it != pend.end(); it++){
		cout << it->first << " " << it->second << endl;
	}*/
	
	llint ans = 1;
	for(auto it = pend.begin(); it != pend.end(); it++){
		ans *= (it->second+1)*(it->second+1);
		ans %= mod;
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		ans *= it->second+1, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}