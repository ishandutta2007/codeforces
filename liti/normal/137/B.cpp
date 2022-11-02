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

const int maxN = 5000 + 20 ; 
int a[ maxN ] ; 

int main() 
{
	int n; 
	cin >> n;  
	for(int i = 0 ; i < n ;i++ ) 
	{
		int x;
		cin >> x; 

		a[x]++;
	}

	int ans = 0;

	for(int i = 1 ; i < maxN ;i++ )
	{
		if ( a[i] != 0 ) 
			ans += a[i] - ( i > n ? 0 : 1 ) ; 
	}

	cout << ans << endl;
}