#include <iostream>
#include <map>
#define llint long long

using namespace std;

llint n, m;
llint p[200005];
llint sum[200005];
llint pos;
map<llint, llint> mp1, mp2;

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	for(int i = 1; i <= n; i++){
		if(p[i] == m){
			sum[i] = sum[i-1];
			pos = i;
		}
		if(p[i] < m) sum[i] = sum[i-1]-1;
		if(p[i] > m) sum[i] = sum[i-1]+1;
	}
	for(int i = 0; i < pos; i++) mp1[sum[i]]++;
	for(int i = pos; i <= n; i++) mp2[sum[i]]++;
	
	llint ans = 0;
	for(auto it = mp1.begin(); it != mp1.end(); it++){
		ans += it->second * mp2[it->first];
		ans += it->second * mp2[it->first+1];
	}
	cout << ans << endl;
	return 0;
}