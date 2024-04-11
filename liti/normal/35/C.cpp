#include <iostream> 
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <fstream>

#define cin fin
#define cout fout

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

const int maxN = 2000 + 10;

int a[maxN][maxN];
int main() 
{
	int n,m,k;
	cin >> n >> m >> k; 

	queue<pair<int,int> > bfs;
	for(int i = 0 ; i < k ;i++ )
	{
		int x,y;
		cin >> x >> y; 
		x--;
		y--; 
		a[x][y] = 1; 
		bfs.push(make_pair(x,y));
	}
	
	while ( bfs.size() != 0 ) 
	{
		int x = bfs.front().first;
		int y = bfs.front().second; 
		bfs.pop();

		for(int i = -1 ; i < 2 ; i++ ) 
		{
			for(int j = -1; j < 2; j++ )
			{
				if ( abs(i) + abs(j) == 2 ) 
					continue;
				if ( x + i < 0 || y + j < 0 || x + i == n || y + j == m ) 
					continue; 
				if ( a[x + i][y+j] != 0 ) 
					continue; 
				a[x+i][y+j] = a[x][y] + 1; 
				bfs.push(make_pair(x+i, y+j));
			}
		}
		if ( bfs.size() == 0 ) 
			cout << x + 1 << ' ' << y + 1 << endl;
	}
}