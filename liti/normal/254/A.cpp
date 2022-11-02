#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <deque>

#define SZ(x) (( (int) x.size() ))
#define cin fin
#define cout fout

using namespace std;

const int maxR = 5000 + 10;
int a[maxR];
vector<pair<int, int>  > ans;

ifstream fin( "input.txt" );
ofstream fout( "output.txt" );

int main()
{
	int n;
	cin >> n;
	for(int i = 1 ; i <= 2 * n ; i++ ) 
	{
		int x;
		cin >> x; 
		if ( a[x] != 0 ) 
		{
			ans.push_back(make_pair(a[x],i));
			a[x] = 0;
		}
		else
			a[x] = i;
	}
	if ( SZ(ans) != n ) 
	{
		cout << -1 << endl;
		return 0;
	}

	for(int i = 0 ; i < SZ(ans) ; i++ )
	{
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}
}