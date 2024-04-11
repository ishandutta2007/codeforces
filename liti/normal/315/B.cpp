#include <iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;

	int a[n],b[n];
	for(int i = 0 ; i < n; i++ )
	{
		cin >> a[i];
		b[i] = 0;
	}

	long sum = 0;
	for(int i = 0 ; i < m ; i++ )
	{
		int t; 
		cin >> t;

		if ( t == 1 )
		{
			int v, x;
			cin >> v >> x;
			b[v-1] = sum;
			a[v-1] = x;
		}
		if ( t == 2 ) 
		{
			int y;
			cin >> y; 
			sum += y;
		}
		if ( t == 3 ) 
		{
			int x;
			cin >> x ;
			cout << a[x-1] + sum - b[x-1] << endl;
		}
	}

}