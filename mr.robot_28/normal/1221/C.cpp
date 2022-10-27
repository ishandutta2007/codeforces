#include<bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin >> q;
	for(int i =0; i < q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int k = min(a, min(b, c));
		int sum = k;
		a -= k;
		b -= k;
		c -= k;
		if(a > b)
		{
			swap(a, b);
		}
		sum += min(b - a, a);
		k = min(a, b - a);
		a -= k;
		b -= 2 * k;
		cout << sum + min(a, b) / 3 * 2 + (min(a, b) % 3 == 2) << "\n";
	}
	return 0;
}