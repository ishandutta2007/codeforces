#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


long mem[100];
int main()
{
	ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m ; 

	long a[m+1];
	for(int i =0 ; i < n ; i++ )
	{
		long num;
		cin >> num; 
		int c = 0;	
		while ( num != 0 ) 
		{
			if ( num % 2 ) 
				mem[c]++;
			num/=2;
			c++;
		}

	}
	for(int i = 0 ;i < m ;i++ )
	{
		cin >> a[i];
	}
	sort( a , a  + m  ) ; 

	int ia = 0,imem = 0; 

	int ans = 0; 
	while ( !( ia  == m || imem == 100 ) ) 
	{
		if ( a[ia] <= imem && mem[imem] > 0 ) 
		{
		//	cout << imem << mem[imem] << ' ' << a[ia] << endl;
			ans++;
			ia++;
			mem[imem]--;
	//		cout << a[ia-1] << endl;
			while ( imem > a[ia-1]   ) 
			{
				imem--;
				mem[imem]++;
			}

		}
		else
			imem++;
	}
	cout << ans << endl;
}