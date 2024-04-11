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
	int a, b, c, min = 0;
	cin >> a >> b >> c;
	if(a - b - c + 1 > min)
	{
		min = a - b - c + 1;
	}
	else if( - a + c - b + 1 > min)
	{
		min =  - a + c - b + 1;
	}
	else if( - c + b - a + 1 > min)
	{
		min =  - c + b - a + 1;
	}
	cout << max(0, min);
    return 0;
}