#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n, d, x, y, m;
	cin >> n >> d;
	int A1 = d, B1 = d, C1 = -d * d;
	int A2 = d - n, B2 = n - d, C2 = - (d - n) * d;
	int A3 = d, B3 = d, C3 = -2 * d * n + d * d;
	int A4 =  - n + d, B4 =  - d + n, C4 = (d - n) * d;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		if(x * A1 + B1 * y + C1 >= 0 && A3 * x + B3 * y + C3 <= 0 && A2 * x + B2 * y + C2 >= 0 && A4 * x + B4 * y + C4 <= 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;	
}