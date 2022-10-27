#include<bits/stdc++.h>
 
using namespace std;
#define double long double
const double pi = acos(-1);
pair <double, double> intersect(double x, double y, double r, double x1, double y1, double r1)
{
	double dist = sqrt(x * x + y * y);
	double fi = acos((r1 * r1 + dist * dist - r * r) / (2 * r1 * dist));
	double A1, B1, A2, B2;
	A1 = x * cos(fi) - y * sin(fi);
	B1 = x * sin(fi) + y * cos(fi);
	A2 = x * cos(fi) + y * sin(fi);
	B2 = -x * sin(fi) + y * cos(fi);
	double fi1 = atan2(B1, A1);
	double fi2 = atan2(B2, A2);
	return {fi1, fi2};
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	double d;
	cin >> n >> d;
	vector <pair <double, int> > A;
	for(int i = 0; i < n; i++)
	{
		double x, y, r;
		cin >> x >> y >> r;
		double dist = sqrt(x * x + y * y);
			int cnt = (dist - r) / d;
			if(cnt * d < dist - r)
			{
				cnt++;
			}
			cnt = cnt * d;
			while(cnt <= dist + r)
			{
				pair <double, double> pfi = intersect(x, y, r, 0, 0, cnt); 
				double fi1 = pfi.first;
				double fi2 = pfi.second;
				if(fi1 > 0)
				{
					fi1 = pi * 2 - fi1;
				}
				else
				{
					fi1 = -fi1;
				}
				if(fi2 >= 0)
				{
					fi2 = pi * 2 - fi2;
				}
				else
				{
					fi2 = -fi2;
				}
				if(fi2 < fi1)
				{
					A.push_back({fi1, -1});
					A.push_back({2 * pi, 1});
					A.push_back({0, -1});
					A.push_back({fi2, 1});
				}
				else
				{
					A.push_back({fi1, -1});
					A.push_back({fi2, 1});
				}
				cnt += d;
			}
	}
	sort(A.begin(), A.end());
	int bal = 0;
	int ans = 0;
	for(int i = 0; i < A.size(); i++)
	{
		bal -= A[i].second;
		ans = max(ans, bal);
	}
	cout << ans;
	return 0;
}