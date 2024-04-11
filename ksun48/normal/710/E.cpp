#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL best = 1e16;
LL n, x, y;
LL ans[11000000];
int main(){
	cin >> n >> x >> y;
	ans[0] = 0;
	for(int i = 1; i <= n; i++){
		ans[i] = ans[i-1] + x;
		if(i % 2 && i > 1) ans[i] = min(ans[i],ans[(i+1)/2]+x+y); 
		if(i % 2 == 0) ans[i] = min(ans[i],ans[(i)/2]+y); 
	}
	cout << ans[n] << endl;
}