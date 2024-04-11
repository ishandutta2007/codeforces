#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL cost[400000];
LL quan[400000];
LL s = 0;
LL e = 0;
LL sz = 0;
int main(){
	LL d, n, m;
	cin >> d >> n >> m;
	pair<LL, LL> gas[m+2];
	for(LL i = 0; i < m; i++){
		cin >> gas[i].first >> gas[i].second;
	}
	for(LL i = 0; i < 400000; i++){
		cost[i] = 100000000;
		quan[i] = 0;
	}
	gas[m].first = 0;
	gas[m].second = 0;
	gas[m+1].first = d;
	gas[m+1].second = 0;
	sort(gas, gas+m+2);
	LL ans = 0;
	for(LL i = 1; i < (m+2); i++){
		if(gas[i].first - gas[i-1].first > n){
			cout << -1 << endl;
			exit(0);
		}
	}
	for(LL i = 0; i < (m+2); i++){
		if(i > 0){
			LL val = (gas[i-1].first-gas[i].first);
			while(val < 0){
				if(quan[s] + val <= 0){
					val += quan[s];
					sz -= quan[s];
					ans += cost[s]*quan[s];
					quan[s] -= quan[s];
					s++;
				} else {
					quan[s] += val;
					sz += val;
					ans -= val*cost[s];
					val -= val;
				}
			}
		}
		while(gas[i].second <= cost[e] && e >= s){
			cost[e] = 10000000;
			sz -= quan[e];
			quan[e] = 0;
			e--;
		}
		e++;
		cost[e] = gas[i].second;
		quan[e] = n-sz;
		sz = n;
	}
	cout << ans << endl;
}