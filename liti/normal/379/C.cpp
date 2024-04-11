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

const int maxN = 3*100000 + 100;

pair<int, int> a[maxN];
int b[maxN];

int main() 
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ;i++ )
	{
		cin >> a[i].first ;
		a[i].second = i; 
	}
	sort( a, a + n ) ; 
	
	int bank = 0 ; 

	for(int i = 0 ; i < n ; i++ )
	{
		int index = a[i].second ;
		b[index] = bank + a[i].first ; 
		if ( i != n - 1) 
		{
			if ( a[i].first == a[i+1].first ) 
				bank++;
			else
				bank = max( bank -  ( a[i+1].first - a[i].first - 1 )  , 0 ) ; 
		}
	}

	for(int i = 0 ; i < n ;i++ )
		cout << b[i] << ' ' ;
	cout << endl;
}