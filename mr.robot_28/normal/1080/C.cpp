#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main()
{
	long long q, n, m, x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> n >> m;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		long long x5, y5, x6, y6;
		x5 = max(x1, x3);
		y5 = max(y1, y3);
		x6 = min(x2, x4);
		y6 = min(y2, y4);
		if(x5 <= x6 && y5 <= y6)
		{
			long long sum1 = n * m / 2; // 
			long long sum2 = (n * m + 1) / 2; //
			sum1 -= ((x2 - x1 + 1) * (y2 - y1 + 1) + ((x1 + y1) % 2 == 1)) / 2;
			sum2 += ((x2 - x1 +1 ) * (y2 - y1 + 1) + ((x1 + y1) % 2 == 1)) / 2;
			//cout << sum2 << " " << sum1 << endl;
			sum1 += ((x4 - x3 + 1) * (y4 - y3 + 1) + ((x3 + y3) % 2 == 0)) / 2;
			sum2 -= ((x4 - x3 + 1) * (y4 - y3 + 1) + ((x3 + y3) % 2 == 0)) / 2;
			//cout << sum2 << " " << sum1 << endl;
			//cout << x5 << " " << y5 << " " << x6 << " " << y6 << endl;
			sum1 += ((x6 - x5 + 1)*(y6 - y5 + 1) + ((x5 + y5) % 2 == 1))/ 2;
			//cout << ((x6 - x5 + 1)*(y6 - y5 + 1) + ((x5 + y5) % 2 == 1))/ 2;
			sum2 -= ((x6 - x5 + 1)*(y6 - y5 + 1) + ((x5 + y5) % 2 == 1))/ 2;
			cout << sum2 << " " << sum1 << endl;
			//cout << 1;
		}
		else
		{
			long long sum1 = n * m  / 2; // 
			long long sum2 = (n * m + 1) / 2; // 
			sum1 -= ((x2 - x1 + 1) * (y2 - y1 + 1) + ((x1 + y1) % 2 == 1)) / 2;
			sum2 += ((x2 - x1 + 1) * (y2 - y1 + 1) + ((x1 + y1) % 2 == 1))/ 2;
			sum1 += ((x4 - x3 + 1) * (y4 - y3 + 1) + ((x3 + y3) % 2 == 0)) / 2;
			sum2 -= ((x4 - x3 + 1) * (y4 - y3 + 1) + ((x3 + y3) % 2 == 0)) / 2;
			cout << sum2 << " "<< sum1 << endl;
			//cout << 1;
		}
	}
    return 0;
}