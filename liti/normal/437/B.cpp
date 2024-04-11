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

int main()
{
	int limit, sum;
	cin >> sum >> limit;

	vector<int> ans;

	for(int i = limit ; i >= 1 ; i-- ) 
	{
		int z = 1; 
		int tmp = i;
		while( tmp % 2 == 0 ) 
			tmp /= 2 , z *= 2; 
		if( sum - z >= 0 ) 
			sum -= z, ans.push_back(i) ; 
	}
	if( sum != 0 ) 
		cout << -1 << endl;
	else
	{
		cout << SZ( ans ) << endl;
		for(int i = 0 ; i < SZ( ans ) ; i++ ) 
			cout << ans[i] << ' ';
		cout << endl;
	}

}