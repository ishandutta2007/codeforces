#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main() {
	LL n, k;
	cin >> n >> k;
	LL a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	LL s = 1;
	vector<LL> p;
	while(1){
		p.push_back(s);
		s *= k;
		if(abs(s) > 1e14){
			break;
		}
		int found = 0;
		for(int i = 0; i < p.size(); i++){
			if(p[i] == s) found = 1;
		}
		if(found) break;
	}
	map<LL,LL> freq;
	LL sum = 0;
	LL ans = 0;
	freq[0]++;
	for(int i = 0; i < n; i++){
		sum += a[i];
		for(int i = 0; i < p.size(); i++){
			ans += freq[sum - p[i]];
		}
		freq[sum]++;
	}
	cout << ans << endl;

}