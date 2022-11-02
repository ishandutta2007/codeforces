#include <iostream>
using namespace std;

int c[1001],r[1001];
int main() 
{
	int n, m;
	cin >> n >> m ;

	for(int i = 0  ;i < m ;i++ )
	{
		int x,y; 
		cin >> x >> y; 
		c[y]++;
		r[x]++;
	}

	int k = 1; 
	bool s = false;

	long long ans = 0 ; 
	for(int i = 2 ; i < n; i++ ) 
	{
		if ( c[i] == 0 ) 
			ans++;
		if ( r[i] == 0 ) 
			ans++;
	}

	if ( n % 2 == 1 && c[n/2 + 1] == 0 && r[n/2 + 1] == 0 ) 
		ans-=1;
	cout << ans << endl;

}