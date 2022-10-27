#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '-' && cnt > 0)
		{
			cnt--;
		}
		else if(s[i] == '+')
		{
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}