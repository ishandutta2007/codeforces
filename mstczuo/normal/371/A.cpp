# include <iostream>
# include <cstdio>
using namespace std;

int main()
{
	int a[102], n, k, m, ans = 0;
	cin >> n >> k; m = n / k;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<k; i++) {
		int t = 0;
		for(int j=i; j<n; j+=k)
			if(a[j] == 1) t++;
		ans += min(t, m-t);
	}
	cout << ans << endl;
	return 0;
}