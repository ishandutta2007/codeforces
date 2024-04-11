#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld N;
lld D[88];

int main()
{
	cin >> N;
	D[1] = 2, D[2] = 3;
	for (int i=3;i<88;i++)
		D[i] = D[i-1] + D[i-2];
	int ans = 0;
	for (int i=1;i<88;i++) if (D[i] <= N)
		ans = i;
	cout << ans << endl;
}