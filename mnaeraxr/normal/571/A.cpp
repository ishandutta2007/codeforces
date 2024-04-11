#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 t1(int64 a){
	return a * (a + 1) / 2;
}

int64 t2(int64 a){
	return a * (a - 1) * (a - 2) / 6;
}

int64 solve(int a, int b, int c, int l){
	int64 ans = 0;
	for (int y = 0; y <= l; ++y){
		int x = min(l - y, c + y - a - b);
		x = max(x, -1);
		ans += t1(x + 1);
	}
	return ans;
}

int main()
{
	int a, b, c, l;
	cin >> a >> b >> c >> l;

	int64 ans = t2(l + 3) -( 
				solve(a, b, c, l) + 
				solve(a, c, b, l) +
				solve(b, c, a, l)
				);

	cout << ans << endl;
}