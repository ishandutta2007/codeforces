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

const int maxN = 4000 + 10; 

long long a[maxN];

long long n;

long long find( long long num ) 
{

	long long ans = 0 ; 
	long long sum = 0 ; 

	int last = 0;
	int zCounter = 0 ;  
	for(int i = 0 ; i < n ; i++ )
	{
		sum += a[i];
		while ( a[last] == 0 && last != i ) 
		{
			zCounter++;
			last++;
		}
		while ( sum > num && last != i ) 
		{
			sum -= a[last];
			if ( a[last] != 0 ) 
				zCounter = 0 ; 
			last++;
		}
		while ( a[last] == 0 && last != i ) 
		{
			zCounter++;
			last++;
		}

		if ( sum == num ) 
			ans+= 1 + zCounter;
	//	cout << i << ' ' << zCounter << ' ' << sum << endl;
	}

//	cout << num << ' ' << ans << endl;
	return ans;
}

int main() 
{
	long long num;
	cin >> num;

	string s; 
	cin >> s; 

	n = SZ( s ) ; 
	for(int i = 0; i < n ;i++ ) 
	{
		a[i] = s[i] - '0';
	}

	if ( num == 0 ) 
	{
		long long ans = 0 ; 
		long long x = find(0);
		ans = ( ( n + 1 ) * n ) / 2 ;

//		cout <<  x << ' ' <<  ans << endl;

		ans = (x*( ans - x )  * 2) + (x*x); 
		cout << ans << endl;
		return 0;
	}
	long long ans = 0 ; 
	for(int i = 1 ; i <= min(num, 40000LL); i++ ) 
	{
		if ( num % i != 0 ) 
			continue;
		ans += find(i) * find( num / i );	
	}

	cout << ans << endl;
}