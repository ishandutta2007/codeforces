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

int p[500],q[500];
int main()
{
	int d,s;
	cin >> d >> s; 
	int s1 = 0 , s2 = 0 ; 

	for(int i = 0 ; i < d ; i++ ) 
	{
		int a,b;
		cin >> a >> b;
		p[i] = a; 
		q[i] = b;
		s1 += a;
		s2 += b; 
	}

	if (!( s >= s1 && s <= s2 ) )
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	int x = s - s1; 
	for(int i = 0 ; i < d ; i++ ) 
	{
		int ans = p[i];
		int y = q[i] - p[i];
		int tmp = min(x,y);
		x-=tmp;
		y = tmp ; 
		cout << ans + y << ' ' ;
	}
	cout << endl;
}