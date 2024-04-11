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

const int maxN = 101 ; 
int a[maxN];

int main() 
{
	int n;
	cin >> n; 

	for(int i = 0 ; i < n ;i++ )
		cin >> a[i];

	int bestAns = 0 ; 
	for(int i = 0 ; i < n ; i++ ) 
	{
		int x = 0;
		for(int j = i ; j < n ;j++ )
		{
			x ^= a[j];
			if ( x > bestAns ) 
				bestAns = x; 
		}
	}

	cout << bestAns << endl;
}