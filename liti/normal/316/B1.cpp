#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

bool a_find(vector<int>& p, int n1, int n2) 
{
	while( p[n1] != n1 ) 
		n1 = p[n1];
	while( p[n2] != n2 )
		n2 = p[n2];

	if ( n1 == n2 ) 
		return true;
	return false;
}

void a_union(vector<int>& p, vector<int>& h, int n1, int n2)
{
	
	p[n2] = n1;
	h[n1]+= h[n2];
	while ( p[n1] != n1 ) 
	{
		n1 = p[n1];
		h[n1]+= h[n2];
	}
//	cout << n1 << ' ' << n2 << ' ' << h[n1] << p[n2] <<  endl;
}


int main()
{
	int n, x;
	cin >> n >> x ; 
	vector<int> p;
	vector<int> h;

	x--;
	for(int i = 0 ; i < n; i++ )
	{ 
		p.push_back(i);
		h.push_back(1);
	}

	int num;
	for ( int i = 0 ; i < n ; i++ ) 
	{
		cin >> num; 
		if ( num == 0 ) 
			continue;
		a_union(p,h,num - 1 , i);
	}	

	
	int constant=0;
	int r[n];
	for(int i = 0 ; i < n; i++) 
		r[i] = -1;
	for(int i = 0 ; i < n ; i++ )
	{
		int counter = 0;
		int j = i;
		while ( p[j] != j )
		{
			j = p[j]; 
			counter++;
		}
		if ( r[j] == -1 )
			r[j] = h[j];
		if ( i == x ) 
		{
			constant = counter + 1;
			r[j] = -2;
		}
	}
	
	sort( r , r + n ) ;
	long sum = 0;
	int last = -1;
	bool javab[n+1];
	for(int i = 0 ; i < n+1 ;i++)
		javab[i] = false;
	javab[constant] = true;
	for(int i = 0 ;i < n ;i++ ) 
	{
		if ( r[i] <= -1 ) 
			continue;
		if ( last == -1 ) 
		{
			javab[r[i] + constant] =  true;
			last = r[i];
			continue;
		}
		
		
		for(int j = n ; j >= 0 ; j-- ) 
		{
			if ( javab[j] ) 
			{
				javab[j + r[i]] = true;
			}
		}

		last = r[i];
				
	}	
	for(int i = 0 ; i < n+1 ; i++ )
		if ( javab[i] ) 
			cout << i << endl;
}