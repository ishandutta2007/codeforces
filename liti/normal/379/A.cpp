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
	int a,b;
	cin >> a >> b;

	int ans = a; 
	while ( a / b != 0 ) 
	{
		ans += a/b;
		a = ( a % b ) + a/b; 
	}
	cout << ans << endl;
}