#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint a[100005], b[100005];
llint p[100005];

bool comp(int i, int j)
{
	return b[i]-a[i] < b[j]-a[j];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i= 1; i <= n; i++) cin >> a[i] >> b[i];
	
	for(int i = 1; i <= n; i++) p[i] = i;
	sort(p+1, p+n+1, comp);
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) ans += a[p[i]]*(i-1) + b[p[i]]*(n-i);
	cout << ans << endl;
	
	return 0;
}