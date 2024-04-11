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

const int maxN = 1048576 + 10; 

long long inv[20 + 2];

long long invArr[maxN];
long long tmpArr[maxN];

long long had[20 + 2];


long long merge( int s, int e, int ind ) 
{
	long long ret = 0; 
	int m = ( s + e ) / 2 ; 

	int i1 = s, i2 = m;
	for(int i  =s ; i < e ; i++ ) 
	{
		if( i1 == m ) 
		{
			tmpArr[i] = invArr[i2];
			i2++;
		}
		else if( i2 == e ){ 
			tmpArr[i] = invArr[i1];
			i1++;
		}
		else if( invArr[i1] <= invArr[i2] ) 
		{
			if( invArr[i1] == invArr[i2] ) 
			{
				int val = invArr[i1];
				if( i1 == s || invArr[i1] != invArr[i1-1] ) 
				{
					int c1 = 0, c2 = 0;
					int t1 = i1, t2 = i2;
					while( t1 != m && invArr[t1] == val ) 
					{
						c1++;
						t1++;
					}	
					while( t2 != e && invArr[t2] == val ) 
					{
						c2++;
						t2++;
					}	
		//			cout << ind << ' ' << c1 << ' ' << c2 << endl;
					had[ind] -= c1*c2;
				}
			}

			tmpArr[i] = invArr[i1];
			i1++;
		}
		else
		{
			tmpArr[i] = invArr[i2];
			i2++;
			ret+= ( m - i1 );
		}
	}
	for(int i = s ; i < e ; i++ ) 
		invArr[i] = tmpArr[i];

	return ret;
}

void setInv( int s, int e , int ind, int n) 
{
	if(  e - s  == 1 ) 
		return;

	int m = ( s + e ) / 2; 
	setInv( s, m, ind+1,n ) ; 
	setInv( m, e, ind+ 1 ,n) ;	

	inv[ind] += merge( s, e, n- ind ); 

//	cout << s << ' ' << e << ' ' << inv[ind] << endl;
}

void init(int n)
{
	long long y = 1<<n;
	had[0] = 0;
	long long  x = 1;
	for(int i = 1 ; i <= n ; i++ ) 
	{
		had[i] = x*x* ( y / (2*x) ) ;
		x*=2;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n;
	long long x = 1<<n;
	for(int i = 0; i < x ; i++ ) 
		cin >> invArr[i];

	init(n);
//	for(int i = 0 ; i <= n ; i++ ) 
//		cout << i << ' ' << had[i] << endl;


	setInv(0,x, 0,n);
//	for(int i = 0 ; i <= n ; i++ ) 
//		cout << i << ' ' << had[i] << endl;

//	cout << endl << endl;

	cin >> m;

	for(int i = 0; i< m ; i++ )
	{ 
		int q;
		cin >> q;

		long long ans = 0;
		for(int i = q; i >= 0 ; i-- ) 
			inv[n-i] = had[i] - inv[n-i];

		for(int i  = 0;i <=n ; i++ ) 
		{
//			cout << i << ' '  << inv[i] << endl;
			ans += inv[i];
		}
		cout << ans << endl;

	}

}