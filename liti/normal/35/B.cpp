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

const int maxN = 31 + 10;
string a[maxN][maxN];

int n,m;

void aadd()
{
	int x, y; 
	string id ; 
	cin >> x >> y >> id; 
	x--;
	y--; 
	for(int i = x; i < n ; i++ ) 
	{
		bool canDo = false;
		for(int j = ( i == x ? y : 0 ) ; j < m ; j++ ) 
		{
			if ( a[i][j] == "" ) 
			{
				a[i][j] = id; 
				canDo = true;
				break;
			}
		}
		if ( canDo ) 
			break;
	}

}

void rremove()
{
	string id; 
	cin >> id; 
	for(int i = 0 ; i < n ;i++ )
	{
		for(int j = 0 ; j < m ;j++ )
		{
			if ( a[i][j] == id ) 
			{
				a[i][j] = "";
				cout << i + 1 << ' ' << j + 1 << endl;
				return ; 
			}
		}
	}
	cout << -1 << ' ' << -1 << endl;
}

int main() 
{
	int k;
	cin >> n >> m >> k; 
	for(int i =0 ; i < n ; i++ )
		for(int j = 0 ;  j < n ; j++ )
			a[i][j] = "";
	for(int i = 0 ; i < k ; i ++ ) 
	{
		string x,s;
		cin >> x;
		if ( x == "-1" ) 
			rremove();
		else
			aadd();
	}
}