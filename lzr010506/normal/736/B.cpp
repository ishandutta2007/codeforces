#include <bits/stdc++.h>
using namespace std;

bool pd(int x)
{
	int N = sqrt(x);
	for(int i = 2; i <= N; i ++)
		if(x % i == 0) return 0;
	return 1;
}

int main()
{
	int n;
	cin >> n;

	if(pd(n) == 1) cout << 1;
	else if(n % 2 == 0 || pd(n - 2) == 1) cout << 2;
	else cout << 3;

	return 0;
}