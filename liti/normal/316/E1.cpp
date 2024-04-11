#include <iostream>
using namespace std;

long long f[100];
int main()
{
	f[1] = 1;
	f[0] = 1;
	for(int i = 2 ; i < 100 ; i++ ) 
	{
		f[i] = f[i-1] + f[i-2];
		f[i] = f[i] % 1000000000LL;
	}

	int n,m;
	cin>> n >> m;
	int a[n];
	for(int i = 0 ; i < n; i++ ) 
	{
		cin >> a[i] ;
	}
	int t,x,v,l,r;
	for(int i = 0 ; i < m ; i++ ) 
	{
		cin >> t;
		if ( t == 1 ) 
		{
			cin >> x >> v;
		   a[x-1] = v;	
		}
		if ( t== 2) 
		{
			cin >> l >> r;
			long long sum = 0;
			for(int j = l - 1 ; j < r ; j++ ) 
				sum =  ( sum +  (  f[ j - ( l - 1 ) ] * a[j] ) ) % 1000000000LL ;
			cout << sum << endl;
		}
	}

}