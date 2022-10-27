#include <bits/stdc++.h>
using namespace std;

 
signed main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int b, p, f;
		cin >> b >> p >> f;
		int h, c;
		cin >> h >> c;
		if(h < c)
		{
			swap(h, c);
			swap(p, f);
		}
		int v = min(b / 2, p);
		int cnt = v * h;
		b -= v * 2;
		cnt += min(b / 2, f) * c;
		cout << cnt << "\n";
	}
	return 0;
}