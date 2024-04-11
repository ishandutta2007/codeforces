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

const int maxN = 100*100*10 + 10; 
int a[maxN];

int main() 
{
	int n,k;
	cin >> n >> k ; 

	if ( n == k ) 
	{
		cout << -1 << endl;
		return 0;
	}

	for(int i = 1 ;i <= n ;i++ ) 
		a[i] = i; 

	int x = n - k ; 
	if ( x % 2 == 0 ) 
	{
		swap( a[1], a[n] ) ; 
		x--;
	}

	x--;

	for(int i = 2; i < n ; i += 2 ) 
	{
		if ( x >  0 ) 
		{
			swap( a[i], a[i+1] ) ;
			x-=2;
		}
		else
			break;
	}

	for(int i = 1 ; i <= n ;i++ )
		cout << a[i] << ' ' ; 
	cout << endl;
}