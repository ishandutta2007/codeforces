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
	int a ,c ;
	int b = 0 ; 
	cin >> a >> c;

	int x = 1; 
	while ( !( c == 0 && a == 0 ) ) 
	{
		int nD = ( ( c % 3 ) + 3 - ( a % 3 ) ) % 3 ; 

		b += x * nD;
		c/=3;
		a/=3;
		x*=3;
	}

	cout << b << endl;
}