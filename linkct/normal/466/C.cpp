#include <iostream>
#define MAX 500005
using namespace std;
typedef long long int ll;

int n, seq[MAX], suf[MAX];
ll tot, pref[MAX];

int main(){
	int i;
	ll ans = 0;
	cin >> n;
	for(i = 1; i <= n; ++ i){
		cin >> seq[i];
		pref[i] = pref[i - 1] + seq[i];
		tot += seq[i];
	}
	if(tot % 3){
		cout << 0 << endl;
		return 0;
	}
	tot /= 3;
	for(i = n - 1; i; -- i)
		suf[i] = suf[i + 1] + ((pref[i] == tot * 2) ? 1 : 0);
	for(i = 1; i < n; ++ i)
		if(pref[i] == tot)
			ans += suf[i + 1];
	cout << ans << endl;
	return 0;
}