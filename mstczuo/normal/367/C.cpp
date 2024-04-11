# include <iostream>
# include <cstdio>
# include <algorithm>
# include <functional>
using namespace std;

long long a[100010];
int n, m, t;
long long c, ans;
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++)
		cin >> t >> a[i];
	sort(a, a+m, greater<int>());
	for(int i=0; i<m; i++)
		a[i+1] += a[i];
	for(int i=1; i<=m; i++) {
		if(i&1) c = 1LL * i*(i-1)/2;
		else c = 1LL * i*(i-1)/2 + (i-2)/2;
		if( n > c ) ans = a[i-1];
	}
	cout << ans << endl;
	return 0;
}