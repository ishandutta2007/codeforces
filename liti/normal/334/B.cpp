#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


	vector< pair<int, int> > p;

	map<int,int> x, y;
	int a[3],b[3];
bool c( pair<int,int> a, pair<int,int> b) 
{
	return ( a.second < b.second ) ;
}
int main() 
{

	for(int i =0 ; i < 8 ; i++ )
	{
		int x,y;
		cin >> x >> y;
		p.push_back( make_pair(x,y));
	}
	sort( p.begin(), p.begin() + 8 , c ) ; 
	sort( p.begin() , p.begin() + 8  ) ; 

	bool check = true;


	int c[3] = {0,3,5};
	for(int i =0 ; i < 3 ;i++ )
	{
		if ( x.find( p[c[i]].first ) != x.end() ||  y.find( p[i].second ) != y.end()  ) 
		{

			cout << "ugly" << endl;
			return 0 ; 
		}
		y[p[i].second] = i; 
		x[p[c[i]].first] = i;
	}


	
	for(int i =0; i < 8 ;  i++ )
	{
		if ( x.find( p[i].first )  == x.end() || y.find( p[i].second ) == y.end() ) 
		{
			cout << "ugly" << endl;
			return 0;
		}
		a[x[ p[i].first ] ] ++;
		b[y[ p[i].second ] ] ++;
	}

	if ( a[0] == 3 && a[1] == 2 && a[2] == 3 && b[0] == 3 && b[1] == 2 && b[2] == 3 ) 
	{
		cout << "respectable" << endl;
		return 0; 
	}
	cout << "ugly" << endl;
}