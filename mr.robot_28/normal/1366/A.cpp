#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		int e = fabs(a - b);
		e = min(e, a);
		e = min(e, b);
		a -= e;
		b -= e;
		if(b > a)
		{
			b -= e;
		}
		else
		{
			a -= e;
		}
		int c = min(a, b) / 3;
		a -= c * 3;
		b -= c * 3;
		if(a >= 1 && b >= 2 || a >= 2 && b >= 1)
		{
			e++;
		}
		cout << e + c *  2 << "\n";
	}
    return 0;
}