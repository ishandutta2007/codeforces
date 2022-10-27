#include<bits/stdc++.h>
 
using namespace std;
#define int long long
#define double long double
const double eps = 1e-9;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, r, v;
	cin >> n >> r >> v;
	for(int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		int len = en - st;
		double li = 0, ri = 1e9;
		while(ri - li > eps)
		{
			double midd = (ri + li) / 2;
			double a = midd + sqrt((cos(midd / r) - 1) * (cos(midd / r) - 1) + sin(midd / r) * sin(midd / r)) * r;
			if(a <= len)
			{
				li = midd;
			}
			else
			{
				ri = midd;
			}
		}
		cout << fixed << setprecision(10) << li / v << "\n";
	}
	return 0;
}