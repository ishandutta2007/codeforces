#pragma gcc optimize("O3");
#pragma gcc target("sse4");
#include <iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<stack>
using namespace std;
int main()
{
	int t, l, u, l1, r;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> l >> u >> l1 >> r;
		int count = l / u;
		count -= r / u;
		if(l1 % u == 0)
		{
			l1--;
		}
		count += l1 / u;
		cout << count << endl;
	}
    return 0;
}