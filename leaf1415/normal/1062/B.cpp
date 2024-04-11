#include <iostream>
#include <map>

using namespace std;

int n;
bool prime[1000005];
int beki[25];
map<int, int> mp;

int main(void)
{
	cin >> n;
	if(n == 1){
		cout << 1 << " " << 0 << endl;
		return 0;
	}
	
	beki[0] = 1;
	for(int i = 1; i < 25; i++) beki[i] = beki[i-1]*2;
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		while(n % i == 0){
			mp[i]++;
			n /= i;
		}
	}
	if(n > 1) mp[n]++;
	
	int mx = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		mx = max(mx, it->second);
	}
	
	int keta = 0;
	for(int i = mx; i; i/=2) keta++;
	for(int i = 0; i < 25; i++){
		if(mx == beki[i]){
			keta--;
			break;
		}
	}
	
	int ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it->second != (1<<keta)){
			ans++;
			break;
		}
	}
	ans += keta;
	
	int val = 1;
	for(auto it = mp.begin(); it != mp.end(); it++){
		val *= it->first;
	}
	cout << val << " " << ans << endl;
	return 0;
}