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
	int n,k;
	cin >> n >> k; 

	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = 0 ; j < n ; j++ )
		{
			if ( i == j ) 
				cout << k << ' ' ;
			else
				cout << 0 << ' ' ;
		}
		cout << endl;
	}
}