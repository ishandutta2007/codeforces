#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <deque>

#define SZ(x) (( (int) x.size() ))

using namespace std;

main()
{
	int n,x,y;
	cin >> n >> x >> y; 

	cout << min( n - x, y + 1 ) << endl;
}