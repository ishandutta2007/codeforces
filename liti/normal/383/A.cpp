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

const int maxN = 200*100*10 + 100;

int a[maxN];

int main()
{
	int n;
	cin >> n;

	for(int i = 0 ; i < n ;i++ )
		cin >> a[i];

	long long ans = 0 ;
   long long counter = 0; 	
	for(int j = 0 ; j < n ; j++ ) 
		if ( a[j] == 0 ) 
			ans += counter;
		else
			counter++;
	cout << ans << endl;
}