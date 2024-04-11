#include <iostream>
#include <queue>

using namespace std;

long long a[ (1<<17) + 1][18];

int main() 
{
	long long n,m;
	cin >> n >> m; 
	long long t = 1<<n; 

//	cout << t<<endl;
	queue<long long> q;
	int c = 0;
	for(long long i = 1 ; i <= t; i++ ) 
	{
		cin >> a[i][c] ; 
		q.push(a[i][c]);
	}

	bool o = true;
	c++;
	while ( q.size() != 1 ) 
	{
		
		int x = q.size() / 2; 
		for(int i = 1 ; i <= x ;i++ )
		{
			long long e,f;
			e = q.front();
			q.pop();
			f = q.front();
			q.pop();
			if ( o ) 
			{
				q.push( e | f ) ;
				a[i][c] = e | f;
			}
			else
			{
				q.push( e ^ f ) ;
				a[i][c] = e ^ f;
			}
		}
		o = !o;
		c++;
	}
	a[1][c] = q.front();
//	cout << a[1][c] << endl;

	for(long long i = 0 ; i < m ; i++ ) 
	{
		long long p,b;
		cin >> p >>b;

		int index = 0;
		while ( index != n ) 
		{
			long long d = p - 1;
			if ( p % 2 == 1 ) 
				d = p + 1;
			a[p][index] = b;
//			cout << d << ' ' << p << endl;
			if ( index % 2 == 0 ) 
				a[(p+1)/2][index+1] = a[p][index] | a[d][index] ;
			else
				a[(p+1)/2][index+1] = a[p][index] ^ a[d][index] ;
			b = a[(p+1)/2][index+1] ;
//			cout << b << endl;
			p = (p+1)/2;
			
			index++;
		}

		cout << a[1][index] << endl;
	}
	
}