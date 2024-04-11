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

vector<int> s[3];
int val[3];

vector<int> e[7];
string names[7] = {
	"Anka",
	"Chapay",
	"Cleo",
	"Troll",
	"Dracul",
	"Snowy",
	"Hexadecimal"
};

int a1, a2;

void doJob()
{
	int exp[3];
	for(int i = 0 ; i < 3; i++ )
		exp[i] = val[i]/SZ(s[i]);
	int ans = max( exp[0], max( exp[1], exp[2] ) ) - min( exp[0], min( exp[1], exp[2] ) ) ; 
	if ( ans > a1 ) 
		return;
	if ( ans < a1 ) 
	{
		a1 = ans;
		a2 = 0;
	}

	int like = 0 ; 
	for(int i = 0 ; i < 3 ; i++ )
		for(int j = 0 ; j < SZ( s[i] ) ; j++ )
			for(int y = 0 ; y < SZ(s[i]) ; y++ )
				for(int k= 0; k < SZ( e[ s[i][j] ] ) ; k++ )
					if ( e[ s[i][j] ][k] == s[i][y] ) 
						like++;
	a2 = max( a2, like ) ;
}

void calc(int x)
{
	if ( x == 7 ) 
	{
		bool check = true;
		for(int i = 0 ; i < 3 ;i++ ) check &= ( SZ( s[i] ) != 0 ) ;
		if ( check ) 
			doJob();
		return;
	}
	for(int i = 0 ; i < 3 ; i++ )
	{
		s[i].push_back(x);
		calc(x+1);
		s[i].pop_back();
	}
}

int main()
{
	a1 = 1000*1000*1000;
	a2 = 0 ; 
	int n;
	cin >> n;

	string tmp;
	for(int i =0 ; i < n ;i++ )
	{
		int x,y;
		string xs, ys;
		cin >> xs >> tmp >> ys;
		for(int j = 0 ; j < 7 ; j++ )
			if ( names[j] == xs ) 
				x = j;
		for(int j = 0 ; j < 7 ; j++ )
			if ( names[j] == ys )
				y = j ;
		e[x].push_back(y);
	}

	for(int i =  0 ; i < 3 ; i++ ) 
		cin >> val[i];

	calc(0);

	cout << a1 << ' ' << a2 << endl;
}