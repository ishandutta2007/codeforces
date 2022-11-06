#include <bits/stdc++.h>
using namespace std;
int f[5000010], d, n, w;
int main()
{
	cin >> n >> d;
	f[0] = 1;
	int sum = 0;
	for(int i = 1; i <= n; i ++)
	{
	    int x;
		cin >> x;
		sum += x;
		for(int j = sum; j >= x; j --)
			if(f[j - x]) f[j] = 1;
	}
	int j = 0, ans = 0;
	while(1)
	{
		j = w + d;
		while(!f[j] && j > w) j --;
		if(j == w) break;
		w = j;
		ans ++;
	}
	cout << w << " " << ans;
	return 0;
}