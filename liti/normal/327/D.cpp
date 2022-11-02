#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <deque> 
#include <vector> 

using namespace std;

int main() 
{
	int n,m;
	cin >> n >> m; 
	
	
	int a[n][m];
	for(int i = 0 ; i < n ; i++ ) 
	{
		string s; 
		cin >> s ; 
		
		for(int j = 0 ; j < m ; j++ ) 
		{
			char c = s[j]; 
			
			if ( c== '#' ) 
				a[i][j] = -2; 
			else
				a[i][j] = -1; 
		}
	}
	
	
	long long counter = 0; 
	vector<pair< int, int > > ans ; 
	
	for(int i = 0 ; i < n ; i++ ) 
	{
		for(int j =0 ; j < m ; j++ ) 
		{
			if ( a[i][j] == -1 ) 
			{
				counter += 1; 
				
				
				deque<pair < int , int> > bfs; 
				bfs.push_back( make_pair( i , j ) ) ; 
				ans.push_back( make_pair( i , j ) ) ;
				a[i][j] = 1;
				vector< pair<int, int > > r ;  
				while ( bfs.size() != 0 ) 
				{
					pair<int,int> current = bfs.front(); 
					int x = current.first , y = current.second; 
					
					for(int q = -1 ; q < 2 ; q++ ) 
					{
						for(int w = -1 ; w < 2 ; w++ ) 
						{
							if ( q != 0 && w != 0 ) 
								continue;
							
							if ( x + q < 0 || x + q > n - 1 || y + w < 0 || y + w > m - 1 ) 
								continue;
							if ( a[x+q][y+w] == -1 ) 
							{
								counter++; 
								ans.push_back( make_pair( x + q, y + w ) ) ; 
								bfs.push_back( make_pair( x + q, y + w ) ) ; 
								a [ x + q] [ y + w ] = 1 ; 
							}
						}
					}
					
					if ( ! ( x == i && y == j ) ) 
					{
						r.push_back(make_pair( x,y) ) ;
						counter+=2; 
					}
					
			//		cout << bfs.size() << endl;
					bfs.pop_front(); 
				}
				
				for(int q = r.size() - 1 ; q >= 0 ; q-- ) 
					ans.push_back( r[q] ) ;
				
				
			}
		}
		
					
		
	}
	
		cout << counter << endl;
		
		for(int i =0  ; i < ans.size() ; i++ ) 
		{
			int x = ans[i].first  , y = ans[i].second ; 
			
			if ( a[x][y] == 1 ) 
			{
				cout << "B " << x+1 << ' ' << y+1  << endl;
				a[x][y] = 2;
				continue;
			}
			if ( a[x][y] == 2 ) 
			{
				cout << "D " << x+1 << ' ' << y +1<< endl;
				cout << "R " << x+1 << ' ' << y +1<< endl;
			}
		}
	
	
//	cin >> m;		
}