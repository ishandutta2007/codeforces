#include <iostream>
#include <vector>
#include <map>

using namespace std;

int c[1000][1000],x[1000];
int main() 
{
	int n,m;
	cin >> n >> m;

	map<int,bool> k;
	vector<pair<int, int> > ans;
	for(int i = 0 ; i < m ; i++ ) 
	{
		int a,b; 
		cin >> a >> b;

		a--;
		b--;
		c[a][b] = 1; 
		c[b][a] = 1; 
		x[a]++;
		x[b]++;
	}

	int min = 1001, minId = -1;
	for(int i =0 ; i < n ; i++ ) 
	{
		if ( x[i] < min ) 
		{
			min = x[i];
			minId = i; 
		}
	}

	for(int i = 0; i < n ;i++ ) 
	{
		if ( i == minId ) 
			continue;
		if ( c[minId][i] == 0 ) 
		{
			ans.push_back( make_pair( minId + 1, i + 1 ) ) ; 
		}
		else
		{
			for(int j = 0 ; j < n ; j++ ) 
			{
				if ( c[minId][j] == 0 ) 
				{
					if ( c[j][i] == 0 ) 
					{
						ans.push_back( make_pair( j + 1, i + 1 ) ) ; 
						break;
					}
				}
			}
		}
	}
	cout << ans.size() << endl;
	for(int i  = 0 ;i < ans.size() ; i++ ) 
	{
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}
	
}