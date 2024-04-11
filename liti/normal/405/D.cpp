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
#include <cstdio>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 1000*1000 + 1;

int a[maxN];
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	for(int i = 0; i < n ; i++ ) 
	{
		int tmp;
		cin >> tmp;
		tmp--;
		a[tmp] = 1; 
	}

	int t = 0 ; 
	for(int i = 0 ; i <  maxN ; i++ ) 
		if( a[i]) 
		   	if( a[maxN - i - 2] ) 
				t++;
			else
				ans.push_back( maxN - i - 1 ) ; 
	t /=2; 
	for(int i = 0; i < maxN ; i++ ) 
	{
		if( !t ) 
			break;
	   if(  a[i] == 0 &&  a[ maxN - i - 2 ] == 0 ) 
		   t--, ans.push_back( i + 1 ) , ans.push_back( maxN - i - 1 ) ,  a[i] = 1, a[ maxN -i - 1 ] = 1  ;
	}

	cout << SZ( ans ) << endl;
	for(int i = 0;i < SZ( ans ) ; i++ )
		cout << ans[i] << ' ' ;
	cout << endl;
}