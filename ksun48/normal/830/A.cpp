#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, k, p;
	cin >> n >> k >> p;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);

	int b[k];
	for(int i = 0; i < k; i++) cin >> b[i];
	sort(b,b+k);

	LL ans = 9e16;
	for(int i = 0; i + n-1 < k; i++){
		LL cur = 0;
		for(int j = 0; j < n; j++){
			cur = max(cur, (LL)abs(a[j] - b[i+j]) + (LL)abs(b[i+j]-p) );
		}
		ans = min(ans,cur);
	}
	cout << ans << endl;
}