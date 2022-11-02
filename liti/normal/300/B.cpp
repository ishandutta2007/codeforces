#include <iostream>
#include <vector> 

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

void a_union(vector<int>& p, vector<int>& h, vector<int>&s , int n1, int n2)
{
	int b1 = n1 , b2 = n2;
	while( p[n1] != n1 ) 
		n1 = p[n1];
	while( p[n2] != n2 )
		n2 = p[n2];
	
	if ( h[n2] > h[n1] ) 
	{
		swap( n1, n2 ) ;
		swap( b1, b2 ) ;
	}
	while ( p[b2] != b2 ) 
	{
		p[b2] = n1;
		b2 = p[b2];
	}
	p[n2] = n1;
	h[n1] = max( h[n2] + 1, h[n1] );
	s[n1] = s[n2] + s[n1];
//	cout << n1 << ' ' << n2 << ' ' << h[n1] << p[n2] <<  endl;
}


int main()
{
	int n;
	int m;

	int n1, n2;
	cin >> n ; 
	cin >>  m;
	vector<int> p;
	vector<int> h;
	vector<int> s;

	for(int i = 0 ; i < n; i++ )
	{ 
		p.push_back(i);
		h.push_back(1);
		s.push_back(1);
	}

	
	for(int i = 0; i < m; i++) 
	{
		cin >> n1 >> n2; 
		n1--;
		n2--;
		if ( a_find( p, n1, n2 ) )
		{
//			cout << "they are in a same set" << endl;
		}
		else
		{
//			cout << "they are not in a same set, they are joint together now" << endl;
			a_union(p,h,s,n1,n2);
		}
	}	
	vector< vector<int> > nums;
	for(int i = 0 ; i < n; i++)
	{
		bool check = true;
		for(int j = 0 ; j < nums.size() ; j++ )
			if ( a_find( p, i, nums[j][0] ) )
			{
				check = false;
				nums[j].push_back( i ) ;
				break;
			}
		if ( check ) {

			vector<int> tmp;
			tmp.push_back( i ) ;
			nums.push_back(tmp);
		}
	}
	vector< vector<int> > result[3] ;
	for(int i = 0 ; i < nums.size() ; i ++) 
	{
		if ( nums[i].size() > 3 ) 
		{
			cout << "-1" << endl;
			return 0 ;
		}
		result[ nums[i].size() - 1 ].push_back( nums[i] ) ;
	}
	if ( result[1].size() > result[0].size() ) 
	{
		cout << "-1" << endl;
		return 0; 
	}
	if (  ( ((int)result[0].size()) - ((int)result[1].size()) ) % 3 != 0 ) 
	{
		cout << "-1" << endl;
		return 0;
	}
	int i = 0 ; 
	for(i = 0; i < result[1].size() ; i++) 
	{
		for(int j = 0  ; j <  result[0][i].size(); j++) 
		{
			cout << result[0][i][j] + 1 << ' ';
		}
		for(int j = 0 ; j < result[1][i].size() ; j++ ) 
		{
			cout << result[1][i][j] + 1 << ' ';
		}
		cout << endl;
	}
	i = ((int)result[0].size()) - ((int)result[1].size()) ;
	int tc = 0 ;
	for(int j = result[0].size() - i; j < result[0].size() ; j++ ) 
	{	
		cout << result[0][j][0] + 1 << ' ' ;
		tc ++;
		if ( tc % 3 == 0 ) 
			cout << endl;
	}
	for( i = 0 ; i < result[2].size() ; i++ )
	{
		for(int j = 0 ; j < result[2][i].size() ; j++ )
			cout << result[2][i][j]  + 1 << ' ';
		cout << endl;
	}
//	cout << endl;

}