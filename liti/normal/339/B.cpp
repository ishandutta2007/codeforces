#include <iostream>
using namespace std;

int main() 
{
	int n,m; 
	cin >> n >> m ; 
	long long ans = 0 ; 

	int place = 1; 

	for(int i = 0 ; i < m ; i++ ) 
	{
		int tmp; 
		cin >> tmp; 

		if ( tmp < place ) 
			ans += ( n + tmp ) - place; 
		else
			ans += tmp - place;
		place = tmp;
	}
	cout << ans << endl;
}