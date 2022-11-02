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

using namespace std;

int a[100000];
map<int,int> m;

int main()
{
	int n; 
	cin >> n; 
	int ans = 0 ; 
	bool check = false;
	for(int i =0 ; i < n ; i++ ) 
	{
		cin >> a[i]; 
		if ( a[i] == i ) 
			ans++;
		if ( m.find( a[i] ) != m.end() && m[a[i]] == i ) 
			check = true;
		m[i] = a[i];
	}
	if ( ans == n ) 
		cout << ans << endl;
	else
	{
		cout << ans + 1 + check << endl;
	}
}