#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint a, b, c;
vector<llint> veca, vecc;
llint cnta[200005], cntc[200005];
llint cnta2[200005], cntc2[200005];

llint suma[200005], sumc[200005];
llint suma2[200005], sumc2[200005];

llint cala[200005], calc[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	llint n = a+b+c;
	
	llint x;
	for(int i = 1; i <= a; i++){
		cin >> x;
		cnta[x]++;
	}
	for(int i = 1; i <= b; i++) cin >> x;
	for(int i = 1; i <= c; i++){
		cin >> x;
		cntc[x]++;
	}
	for(int i = 1; i <= n; i++) suma[i] = suma[i-1] + cnta[i];
	for(int i = 1; i <= n; i++) sumc[i] = sumc[i-1] + cntc[i];
	
	for(int i = 1; i <= n; i++){
		cnta2[i] = cnta[i], cntc2[i] = cntc[i];
		if(cnta[i]) cntc2[i] = 1;
		if(cntc[i]) cnta2[i] = 1;
	}	
	for(int i = 1; i <= n; i++) suma2[i] = suma2[i-1] + cnta2[i];
	for(int i = 1; i <= n; i++) sumc2[i] = sumc2[i-1] + cntc2[i];
	
	cala[0] = suma[n];
	for(int i = 1; i <= n; i++){
		cala[i] = suma[n] - suma[i] + i - suma2[i];
	}
	calc[n+1] = sumc[n];
	for(int i = 1; i <= n; i++){
		calc[i] = sumc[i-1] + (n-i) - (sumc2[n] - sumc2[i]);
	}
	
	//for(int i = 0; i <= n+1; i++) cout << suma2[i] << " "; cout << endl;
	//for(int i = 0; i <= n+1; i++) cout << sumc2[i] << " "; cout << endl;
	
	for(int i = n; i >= 1; i--) calc[i] = min(calc[i], calc[i+1]);
	
	llint ans = inf;
	for(int i = n; i >= 0; i--){
		ans = min(ans, cala[i] + calc[i+1]);
	}
	cout << ans << endl;
	
	return 0;
}