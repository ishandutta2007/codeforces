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

using namespace std;

const int maxN = 2*100*100*10 + 10;
map<int,int> b;

int a[maxN];

int n,m,p;
vector<int>  ans;

void findAns( int i ) 
{
	int j = 0 ; 
	for(j = 0 ; j < m ;j++ ) 
	{
		if ( j*p + i >= n ) 
			return;
		int index = j*p + i;
		if ( b.find( a[index] ) == b.end() ) 
			b[  a[index] ] = -1;
		else
			b[ a[index] ]--;
	}

	int t = 0;
	map<int,int>::iterator it = b.begin();
	while ( it != b.end() ) 
	{
	//	cout << it->first << endl;
		t += abs( it->second ) ; 
		it++;
	}

	if ( t == 0 ) 
		ans.push_back(i);

//	cout << t << endl;


	j = (j-1)*p + i;

//	cout << j << endl;

	while ( j + p < n ) 
	{
		t -= abs( b[ a[i] ] ) ; 
		b[ a[i] ] ++;
		t += abs( b[ a[i] ] ) ; 

		j += p;
		i += p;

		if ( b.find( a[j] ) != b.end() ) 
		{
			t -= abs( b[ a[j] ] ) ;
			b[ a[j] ] --;
		}
		else
			b[ a[j] ] = -1;
		t +=  abs( b[ a[j] ] ) ; 

		if ( t == 0 ) 
			ans.push_back( i ) ;
	}

	while ( i < n ) 
	{
		b[ a[i] ]++;
		i += p;
	}
}
		

int main() 
{
	cin >> n >> m >> p;

	for(int i = 0 ; i < n ;i++ ) 
		cin >> a[i];
	for(int i = 0;  i < m ; i++ )
	{
		int num;
		cin >> num;
		if ( b.find( num ) == b.end() ) 
			b[num] = 1;
		else
			b[num] ++;
	}

	for(int i = 0 ; i < p ; i++ )
	{
		findAns(i);
	}	

	sort( ans.begin() , ans.end() ) ; 

	cout << ans.size() << endl;
	for(int i = 0 ; i < SZ( ans ) ; i++ )
		cout << ans[i] + 1 << ' ';
	cout << endl;
}