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
	int n, a;
	cin >> n;
	a = n / 2 + 1;
	cout << a << endl;
	int e = 2, w = 3;
	for(int i = 1; i <= n; i++)
	{
		cout << e / 2 << " " << w / 2 << endl;
		e++;
		w++;
	}
	return 0;
}