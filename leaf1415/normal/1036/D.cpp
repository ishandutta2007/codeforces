#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n, m;
llint a[300005], b[300005];
llint suma[300005], sumb[300005];
set<llint> S;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++) suma[i] = suma[i-1] + a[i];
	for(int i = 1; i <= m; i++) sumb[i] = sumb[i-1] + b[i];
	
	if(suma[n] != sumb[m]){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= m; i++) S.insert(sumb[i]);
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(S.count(suma[i])) ans++;
	}
	cout << ans << endl;
	return 0;
}