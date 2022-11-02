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

const int maxN = 2000 + 10;

int a[maxN];
int main()
{
	int n,k;
	cin >> n >> k;

	for(int i =0 ; i < n ; i++ ) 
		cin >> a[i];
	sort( a, a + n ) ; 

	int  counter = 0; 
	for(int i =2; i < n ;i+=3 ) 
		if( 5 - a[i] >= k ) 
			counter++;
		else
			break;
	cout << counter << endl;
}