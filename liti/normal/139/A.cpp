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

int a[7];

int main()
{
	int n;
	cin >> n ;
	int sum = 0 ; 
	int maxIndex = 0;
	for(int i = 0; i < 7; i++ )
	{
		cin >> a[i];
		sum+= a[i];
		if ( a[i] != 0 ) 
			maxIndex = i;
	}

	int x = n % sum;

	if ( x == 0 ) 
	{
		cout << maxIndex + 1 << endl;
		return 0;
	}
	
	int m = 0 ; 
	for(int i = 0 ; i < 7; i++ )
	{
		m += a[i];
		if ( x <= m ) 
		{
			cout << i + 1 << endl;
			return 0 ; 
		}
	}
}