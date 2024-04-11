#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main()
{
	int q, l , r;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> l >> r;
		long long count;
		if(l % 2 == 0)
		{
			count = (r - l + 1) / 2 * (-1);
			if((r - l) % 2 == 0)
			{
				count += r * pow(-1, r);
			}
		}
		else
		{
			count = (r - l + 1) / 2;
			if((r - l + 1) % 2 != 0)
			{
				count += r * pow(-1, r);
			}
		}
		cout << count << endl;
	}
    return 0;
}