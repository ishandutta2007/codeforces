#include <bits/stdc++.h>
#define llint long long

using namespace std;

llint n;
char a[100005];
char b[100005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	
	llint cnt0 = 0, cnt1 = 0, cnt01 = 0, cnt11 = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == '0'){
			cnt0++;
			if(b[i] == '1') cnt01++;
		}
		else{
			cnt1++;
			if(b[i] == '1') cnt11++;
		}
	}
	llint ans = cnt0 * cnt1;
	ans -= cnt01*cnt11;
	cout << ans << endl;
	
	return 0;
}