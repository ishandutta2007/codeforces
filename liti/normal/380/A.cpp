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

const int maxN = 100*100*10 + 123;

vector<long long> op[maxN];

long long a[2*maxN];

int main()
{
	int m;
	cin >> m;

	for(int i =0 ; i < m ;i++ )
	{
		int t ;
		cin >> t;
		if ( t == 1 ) 
		{
			int num;
			cin >> num;
			op[i].push_back(num);
		}
		else
		{
			int l,c;
			cin >> l >> c; 
			op[i].push_back(l);
			op[i].push_back(c);
		}
	}

	int n;
	cin >> n;

	long long index = -1 ; 
	long long size  = 0 ; 
	for(int i = 0 ; i < n ;i++ )
	{
		long long place;
		cin >> place;
		
		while ( place > size ) 
		{
			index++;
			if ( SZ( op[index] ) == 1 ) 
			{
				size++;
				if ( size < maxN ) 
					a[size] = op[index][0];
				if ( place <= size ) 
					break;
			}
			else
			{
				long long l = op[index][0], c = op[index][1] ; 
				long long in = size;
				size += l*c; 
				for(int j = 0 ; j < c ;j++ )
				{
					int x = 1; 
					while( in + 1 < maxN && x != l+1 )
					{
						in ++ ; 
						a[in] = a[x];
						x++;
					}

					if ( in + 1 >= maxN ) 
						break;
				}
				if ( place <= size )
					break;
			}
		}

		if ( SZ( op[index] ) == 1 ) 
			cout << op[index][0] << ' ';
		else
		{
			long long x = ( place - ( size - op[index][0]*op[index][1] ) - 1  ) % op[index][0] + 1; 
		//	cout << i << ' ' << ( size - op[index][0]*op[index][1] )  << endl;
			cout << a[x] << ' '  ;
		}
	}
	cout << endl;

//	for(int i = 0 ; i < 20 ; i++ )
//		cout << a[i] << ' ' ;
//	cout << endl;

}