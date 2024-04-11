#include <iostream> 
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <cstring>

using namespace std;
 
const long long h = 1e5+1;
long long dist[h],w[h];

vector<int> c[h];
pair<int,int> e[h];
int n,m, p[h];
set<pair<int,int> > d;

int main() 
{
	memset( dist, -1 , sizeof dist ) ; 
	
	cin >> n >> m;

	for(int i = 0 ; i < m ; i++ ) 
	{
		int a,b;
		long long weight ; 
		cin >> a >> b >> weight; 

		c[a].push_back(i);
		c[b].push_back(i);

		w[i] = weight;
		e[i] = make_pair( a, b ) ; 
	}
	
	d.insert( make_pair(0,1) ) ; 
	dist[1] = 0 ; 

	while ( d.size() != 0 && (*d.begin()).first != n ) 
	{
		int node = (*d.begin()).second; 

	//	cout << node << endl;
		d.erase( d.begin() ) ; 
		
		for(int i = 0 ; i < c[node].size() ; i++ ) 
		{
			int index = c[node][i] ;
			int next = e[index].first + e[index].second - node;
			if ( next < 0 ) 
				continue;

			if ( dist[next] == -1 ||  dist[next] > dist[node] + w[index] ) 
			{
				d.erase( make_pair( dist[next], next ) ) ; 
				dist[next] = dist[node] + w[index];
				d.insert(make_pair(dist[next] , next) ) ; 
				p[next] = node;
			}
			
			e[index] = make_pair(-1,-1); 
		}


	}

	if ( dist[n] == -1 ) 
	{
		cout << -1 << endl;
		return 0;
	}

	stack<int> path; 
	while ( n != 0 ) 
	{
		path.push(n); 
		n= p[n]; 
	}

	while( path.size() != 0 ) 
	{
		cout <<path.top() << ' ' ; 
		path.pop();
	}

	cout << endl;
}