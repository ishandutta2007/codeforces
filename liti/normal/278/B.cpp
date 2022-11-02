#include <iostream>
using namespace std;

int main()
{
	int n; 
	cin >> n ;
	string s[n];
	int arr[26];
	for(int i =0; i < n; i ++ ) 
	{
		cin >> s[i]; 
	}

	string r = "a" ; 
	bool check = false;
	while(!check) 
	{
		check = true;
		for(int j = 0 ; j < n ; j++ )
		{
			if ( s[j].find(r) != string::npos ) 
			{
				check =false;
				break;
			}
		}
		if ( !check ) 
		{
			int j = r.size() -1 ;
			while ( 1 ) 
			{
				if ( j == -1 )
				{
					r = "a" + r;
					break;
				}
				if ( r[j] == 'z' ) 
				{
					r[j] = 'a';
					j--;
					continue;
				}
				if ( r[j] != 'z' ) 
				{
					r[j] = r[j] + 1;
					break;
				}
				
			}
		}
//		cout << r << endl;
	}
	cout << r << endl;
}