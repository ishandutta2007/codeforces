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

int a[31],b[31];

int main()
{
	int n;
	cin >> n;

	for(int i = 0 ; i < n; i++ )
		for(int j  = 0 ; j < n ; j++ )
		{
			int tmp;
			cin >> tmp;
			a[i] += tmp;
			b[j] += tmp;
		}
	
	int ans = 0 ; 
	for(int i = 0 ; i < n ; i++ )
		for(int j = 0 ; j < n ; j++ ) 
			if( b[j] > a[i] ) 
				ans++;
	cout << ans << endl;
}