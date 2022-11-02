//In the name of Allah
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r[10],c[10];
int main() 
{
	int n,m; 
	cin >> n >> m; 

	string s[n];
	for(int i = 0  ;i < n ; i++ ) 
	{
		cin >> s[i];
		for(int j = 0 ;j < m ; j++ )
		{
			if ( s[i][j] == 'S' ) 
			{
				r[i]++;
				c[j]++;
			}
		}
	}

	int counter = 0 ; 
	for(int i = 0 ;i < n ; i++ )
		for(int j =0 ; j < m ; j++ )
			if ( s[i][j] == '.' && ( r[i] == 0 || c[j] == 0 ) ) 
			{
				counter++;
			}
	cout << counter << endl;
}