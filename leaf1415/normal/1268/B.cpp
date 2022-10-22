#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint a[300005];
llint cnt[2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		llint l = a[i]/2, r = (a[i]+1)/2;
		cnt[i%2] += l, cnt[(i+1)%2] += r;
	}
	cout << min(cnt[0], cnt[1]) << endl;
	
	return 0;
}