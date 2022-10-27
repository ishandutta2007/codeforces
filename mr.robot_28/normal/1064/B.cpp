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
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		int count = 0;
		while(a > 0)
		{
			count += a % 2;
			a = a / 2;
		}
		long long d = pow(2, count);
		cout << d << endl;
	}
    return 0;
}