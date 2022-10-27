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
	int w, h, k, sum = 0;
	cin >> w >> h >> k;
	for(int i = 0; i < k; i++)
	{
		sum += 2 * w + 2 * h -  4;
		w -= 4;
		h -= 4;
	}
	cout << sum;
    return 0;
}