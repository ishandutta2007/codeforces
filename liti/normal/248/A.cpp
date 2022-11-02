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

int main() 
{
	int n; 
	cin >> n; 

	int s1 = 0 , s2 =  0; 

	for(int i = 0 ; i < n ; i++ )
	{
		int x,y;
		cin >> x >> y; 
		s1 += x; 
		s2 += y; 
	}

	cout << min( s1, n - s1 ) + min( s2, n - s2 ) << endl;
}