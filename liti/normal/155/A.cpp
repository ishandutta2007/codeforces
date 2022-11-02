#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <string>
#include <stack>
#include <cstring>

#define SZ(x) (( (int) x.size() ))

using namespace std;

int main()
{
	int n;
	cin >> n;

	int mi,ma;
	cin >> mi;
	ma = mi; 

	int ans = 0;
	for(int i = 1 ; i < n ; i++ )
	{
		int num;
		cin >> num;
		if ( num < mi )
		{
			mi = num;
			ans++;
		}
		if ( num > ma ) 
		{
			ma = num;
			ans++; 
		}
	}
	cout << ans << endl;
}