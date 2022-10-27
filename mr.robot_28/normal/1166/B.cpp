#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	int k;
	cin >> k;
	vector <char> T;
	T.push_back('a');
	T.push_back('e');
	T.push_back('i');
	T.push_back('u');
	T.push_back('o');
	for(int i = 5; i <= k / 5; i++)
	{
		if(k % i == 0)
		{
			int cnt = 0;
			for(int j = 0; j < i; j++)
			{
				int nc = cnt;
				cnt += 1;
				for(int u = 0; u < k / i; u++)
				{
					cout << T[nc % 5];
					nc++;
				}
			}
			return 0;
		}
	}
	cout << -1;
    return 0;
}