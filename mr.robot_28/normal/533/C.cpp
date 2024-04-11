#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
 //   ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   // cout.tie(NULL);
   	int x1, y1,  x2, y2;
   	cin >> x1 >> y1 >> x2 >> y2;
   	if(x2 >= x1 && y2 >= y1)
   	{
   		cout << "Polycarp";
	}
	else if(x2 >= x1)
	{
		if(y1 <= x2 - x1)
		{
			cout << "Polycarp";
		}
		else
		{
			cout << "Vasiliy";
		}
	}
	else if(y2 >= y1)
	{
		if(x1 <= y2 - y1)
		{
			cout << "Polycarp";
		}
		else
		{
			cout << "Vasiliy";
		}
	}
	else
	{
		cout << "Vasiliy";
	}
    return 0;
}