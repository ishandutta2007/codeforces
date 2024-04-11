#include <iostream>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int n;
int a[300005];
int prime[15000005];
map<int, int> mp;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int d = 0;
	for(int i = 1; i <= n; i++) d = gcd(d, a[i]);
	for(int i = 1; i <= n; i++) a[i] /= d;
	
	bool flag = false;
	for(int i = 1; i <= n; i++){
		if(a[i] > 1){
			flag = true;
			break;
		}
	}
	if(!flag){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 2; i < 4005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 15000005; j+=i) prime[j] = i;
	}
	
	for(int i = 1; i <= n; i++){
		int v = a[i], p;
		while(v > 1){
			p = prime[v];
			if(prime[v] == 0) p = v;
			mp[p]++;
			while(v % p == 0) v /= p;
		}
	}
	
	int ans = n;
	for(auto it = mp.begin(); it != mp.end(); it++){
		ans = min(ans, n - it->second);
	}
	cout << ans << endl;
	
	return 0;
}