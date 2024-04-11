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

const int maxN = 5000 + 10; 

bool t[maxN];
int s[maxN], e[maxN]; 
long long v[maxN];
long long a[maxN];
long long b[maxN];

int main() 
{
	int n,m;
	cin >> n >> m ; 

	for(int i = 0 ; i < m ; i++ )
	{
		int tt,ss,ee;
		long long vv;
		cin >> tt >> ss >> ee >> vv;

		tt--;
		ss--;
		ee--;

		t[i] = tt;
		s[i] = ss;
		e[i] = ee;

		v[i] = vv;
	}

	for(int i = 0 ; i < n ; i++ )
	{
		long long num = 100*100*100*100*100LL*100LL;
		for(int j = m - 1; j >= 0 ; j-- ) 
		{
			if ( s[j] > i || e[j] < i ) 
				continue;
			if ( t[j] ) 
				num = min( v[j] , num ) ; 
			else
				num -= v[j];
		}

		a[i] = min(num, 1000000000LL );
		b[i] = min(num, 1000000000LL );
	}

	bool check = true;

	for(int i = 0 ; i < m ; i++ ) 
	{
		long long maxVal = b[s[i]];
		for(int j = s[i] ; j <= e[i] ; j++ ) 
		{
			if ( !t[i] ) 
				b[j] += v[i];
			else
				maxVal = max( maxVal, b[j] ) ; 
		}	

		if ( t[i] && maxVal < v[i] ) 
		{
			check = false;
			break;
		}
	}

	for(int i = 0 ; i < n ; i++ ) 
		if ( a[i] < -1000000000LL ) 
		{
			check = false;
			break;
		}

	if ( !check ) 
	{
		cout << "NO" << endl;
		return 0; 
	}

	cout << "YES" << endl;
	for(int i = 0 ; i < n ; i++ ) 
		cout << a[i] << ' ' ; 
	cout << endl;
}