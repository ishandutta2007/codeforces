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
	ios::sync_with_stdio(false);
	long long a;
	cin >> a; 

	long long counter = 0; 
	long long num = 1; 

	for(long long  i = 2 ; i * i <= a ; i++ )
	{
		while ( a % i == 0 ) 
		{
			a/=i;
			counter++;
			if ( counter <= 2 ) 
				num *= i; 
			if ( counter > 2 ) 
				break;
		}
		if ( counter > 2 ) break;
	}

	if ( a!= 1 ) 
	counter++;
	if (a != 1 && counter <= 2 ) 
		num *= a;
	if ( counter <= 1 ) 
	{	cout << 1 << endl << 0 << endl;
		return 0;
	}

	if ( counter == 2  ) 
		cout << 2 << endl;
	else
		cout << 1 << endl << num << endl;
}