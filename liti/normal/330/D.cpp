#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int p[1000][1000];

int main() 
{
	int r,c ; 
	cin >> r >> c; 

	string s[r]; 
	int si, sj,ssi,ssj; 

	vector<pair<int , int > > m ;
	for(int i = 0;  i < r ; i++ )
	{
		cin >> s[i];
		for(int j = 0 ;j < c ; j++ )
		{
			if ( s[i][j] == 'E' ) 
			{
				si = i ; 
				sj = j ;
			}
			if ( s[i][j] == 'S' ) 
			{
				ssi  = i; 
				ssj  = j ;
			}
			if ( s[i][j] > '0' && s[i][j] <= '9' ) 
			{
				m.push_back( make_pair( i,j ) ) ; 
			}
		}
	}

	queue< pair<int, int> > q; 

	q.push( make_pair( si, sj ) ) ; 

	p[si][sj] = 1; 
	int dist = -1;
	while ( q.size()  != 0) 
	{
		int x = q.front().first ,y = q.front().second;
		q.pop();
		for(int i = -1 ; i < 2 ; i++ )
		{
			for(int j =-1 ;j < 2 ; j++ ) 
			{
				if (  ( i != 0 && j != 0 ) ) 
					continue;
				if ( i + x < 0 || i + x >= r || y + j < 0 || y +  j >= c ) 
					continue;
				if ( s[i+x][y+j] != 'T' && p[i+x][y+j] == 0 )
				{
					p[i+x][y+j] = p[x][y] + 1;
					q.push(make_pair(i+x,y+j));
				}
			}
		}
	}

	if ( p[ssi][ssj] == 0 ) 
	{
		cout << -1 << endl;
		return 0;
	}
	
	int d = p[ssi][ssj]; 
	int ans = 0 ; 
	for(int i =0 ; i < m.size() ; i++ )
	{
		if (  p[ m[i].first ][m[i].second] == 0 ) 
			continue;
		if ( p[ m[i].first ][m[i].second] <= d ) 
			ans += s[ m[i].first ][ m[i].second] - 48; 
	}
	cout << ans << endl;
}