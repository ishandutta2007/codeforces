#pragma GCC optimize "-O3"
#include<bits/stdc++.h>

using namespace std;

int main()  {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;  cin >> n;
	
	for(int i = 2 ; i <= sqrt(n) ; ++i) {
		if (n % i)  continue;
		int x = 1, y = n;
		while (y % i == 0)  x *= i, y /= i;
		if (y == 1) return 0 * puts("NO");
		if (x < y)  swap(x,y);
		for(int j = 1 ; j < y ; ++j)    {
			if ((n - 1 - j * x) % y)    continue;
			int k = (n - 1 - j * x) / y;
			cout << "YES\n2\n" << k << " " << x << "\n" << j << " " << y;
			exit(0); 
		}
	}
	puts("NO");
}