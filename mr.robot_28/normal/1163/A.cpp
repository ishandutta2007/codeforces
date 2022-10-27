#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	int n, m;
	cin >> n >> m;
	if(m * 2>= n)
	{
		cout << n - m;
	}
	else if(m == 0)
	{
		cout << 1;
	}
	else
	{
		cout << m;
	}
    return 0;
}