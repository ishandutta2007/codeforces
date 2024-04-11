#include <iostream>
#define llint long long

using namespace std;

llint n;
llint x[105], cnt[2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	
	for(int i = 1; i <= n; i++) cnt[x[i]%2]++;
	cout << min(cnt[0], cnt[1]) << endl;
	
	return 0;
}