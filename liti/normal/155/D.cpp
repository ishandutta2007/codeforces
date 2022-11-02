#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <string>
#include <stack>
#include <cstring>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 1000*100 + 123;

vector<int> a[maxN];
int g[maxN]; // gharbal :D

int state[maxN], avv[ maxN ] ; 
int main()
{
	int n;
	cin >> n;

	for(int i = 2 ; i <= n ; i++ )
	{
		if ( g[i] ) 
			continue;

		a[i].push_back(i);
		for(int j = i + i ; j <= n ; j+= i ) 
		{
			a[j].push_back(i);
			g[j] = 1;
		}
	}

	int m;
	cin >> m;

	for(int i = 0 ; i < m ; i++ )
	{
		char s;
		int num;
		cin >> s >> num;

		if ( s == '-' ) 
		{
			if ( state[num] == 0 ) 
				cout << "Already off" << endl;
			else
			{
				state[num] = 0;
				for(int j = 0 ; j < SZ( a[num] ) ; j++ )
					avv[ a[num][j] ] = 0; 
				cout << "Success" << endl;
			}
			continue;
		}

		if ( state[num] == 1 ) 
		{
			cout << "Already on" << endl;
			continue;
		}

		int bad = 0;
		for(int j = 0 ; j < SZ( a[num] ) ; j++ )
			bad = max( bad, avv[ a[num][j] ] ) ; 
		if ( bad != 0 ) 
		{
			cout << "Conflict with " << bad << endl;
			continue;
		}

		state[num] = 1;
		for(int j = 0 ; j < SZ(  a[num] ) ; j++ )
			avv[ a[num][j] ] = num;
		cout << "Success" << endl;
	}
}