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
#include <cstdio>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 1000*100 + 123;
int a[maxN];
int b[maxN];
int c[maxN];

int n,m;

int calcNum(int num)
{
	int r = 0 ; 
	int x = sqrt( num ) ; 
	
	for(int i = 2; i <= x ; i++ ) 
	{
		while( num % i == 0 ) 
		{
			num /= i;
			if( b[lower_bound(b, b + m , i) - b ] == i ) 
				r--;
			else
				r++;
		}
	}	

	if( b[lower_bound( b, b + m, num ) - b ] == num ) 
		r--;
	else if( num != 1 ) 
		r++;
	
	return r;
}

int gcd(int a , int b ) 
{
	if( a == 0 ) 
		return b;
	return gcd( b % a , a ) ; 
}

int main()
{
	cin >> n >> m;
	for(int i = 0 ; i < n; i++ ) 
		cin >> a[i];
	for(int i = 0 ; i < m ; i++ )
		cin >> b[i]; 

	long long sum = 0 ; 
	for(int i = 0 ; i < n ; i++ )
	{
		long long tmp = calcNum(a[i]);
	//	cout << a[i] << ' ' << tmp << endl;

		sum += tmp;
	}
	//cout << sum << endl;
	
	c[0] = a[0];
	for(int i = 1; i < n ; i++ ) 
		c[i] = gcd( a[i], c[i-1] ) ;


	long long x = 1;
	for(int i = n- 1; i >= 0 ; i-- ) 
	{
		c[i] /= x;
		long long tmp = calcNum( c[i] ) ; 

		if( tmp < 0  ) 
		{
			sum -= ( i + 1 ) * tmp;
			x *= c[i];
		}
	}
	cout << sum << endl;
}