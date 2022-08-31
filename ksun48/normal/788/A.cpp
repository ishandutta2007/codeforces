#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	LL n;
	cin >> n;
	LL a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	LL b[n];
	for(int i = 0; i < n-1; i++){
		b[i] = abs(a[i]-a[i+1]);
		if(i % 2 == 1){
			b[i] = -b[i];
		}
	}
	LL c[n];
	c[0] = 0;
	for(int i = 0; i < n-1; i++){
		c[i+1] = c[i] + b[i];
	}
	LL ans = 0;
	LL maxcur = 0;
	LL mincur = 0;
	for(int i = 0; i < n; i++){
		maxcur = max(maxcur, c[i]);
		mincur = min(mincur, c[i]);
		ans = max(ans, c[i] - mincur);
		ans = max(ans, -(c[i] - maxcur));
	}
	cout << ans << endl;

}