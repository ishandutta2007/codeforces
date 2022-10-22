#include <iostream>
#include <stdio.h>
#include <algorithm>
#define llint long long

using namespace std;

llint n, U;
llint E[100005];

int main(void)
{
	cin >> n >> U;
	for(int i = 0; i < n; i++) cin >> E[i];
	
	double ans = -1;
	for(int i = 0; i < n; i++){
		auto p = upper_bound(E+i, E+n, E[i] + U) - 1;
		int id = p - E;
		if(id < i+2) continue;
		ans = max(ans, (double)(E[id] - E[i+1])/ (double)(E[id] - E[i]));
	}
	
	if(ans < -0.5) cout << -1 << endl;
	else printf("%.12f\n", ans);
	return 0;
}