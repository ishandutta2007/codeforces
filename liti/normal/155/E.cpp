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

const int pr = 701;
const int maxN = 100*100*100 + 123;

long long hash[maxN], hash2[maxN] , t[maxN];
int n,m;

long long solve( long long * h ) 
{
	sort( h, h + n ) ; 

	long long counter =1  ; 
	long long ans = 0;

	for(int i  = 1 ; i < n ;i++ )
		if ( h[i] == h[i-1] ) 
			counter++;
		else
		{
			ans += ( counter * ( counter - 1 ) ) / 2;
			counter = 1; 
		}

	ans += ( counter * ( counter - 1 ) ) / 2;
		
	return ans;
}

int main()
{
	cin >> n >> m;

	t[0] = 1; 
	for(int i = 1 ; i < n ;i++ )
		t[i] = pr*t[i-1];

	for(int i = 0 ; i < m ; i++ )
	{
		int x,y;
		cin >> x >> y;
		x--; y--;

		hash[x] += t[y];
		hash[y] += t[x];
	}

	for(int i = 0 ; i < n ; i++ )
		hash2[i] = hash[i] + t[i];

	cout << solve( hash ) + solve( hash2 ) << endl;
}