#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	LL n, k;
	cin >> n >> k;
	vector<LL> a(n);
	vector<LL> s(1, 0);
	LL b = (1<<k) - 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s.push_back(s[i] ^ a[i]);		
	}
	map<LL,LL> freq;
	for(LL i = 0; i < s.size(); i++){
		s[i] = min(s[i], s[i] ^ b);
		freq[s[i]]++;
	}
	LL ans = n * (n+1) / 2;
	for(auto x : freq){
		LL f = x.second / 2;
		LL g = x.second - f;
		ans -= f * (f-1)/2;
		ans -= g * (g-1) / 2;
	}
	cout << ans << endl;
}