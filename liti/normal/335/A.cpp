// In the name of Allah ... The one who just helps
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[26],b[26];

int main() 
{
	string s; 
	cin >> s; 
	for(int  i = 0 ;i < s.size() ; i++ )
		a[ s[i] - 'a' ]++;
	
	int n; 
	
	cin >> n ;

	int counter =0 ;	
	string result = "";

	for(int i = 0 ; i < 26; i++ )
	{
		if ( a[i] != 0 )
		{	
			counter++;
			b[i] = 1;
			result += (char) 'a' + i;
		}
	}

	if ( counter > n ) 
	{
		cout << -1 << endl;
		return 0; 
	}

//	cout << counter << endl;


	for(int i = 0 ; i < n-counter ; i++ )
	{
	//	cout << i << endl;
		int best =-1, bestId= -1; 
		for(int j =0; j < 26; j++ ) 
		{
			if ( a[j] == 0 ) 
				continue;
			if ( ( a[j] / b[j] + ( a[j] % b[j] != 0 ) ) > best ) 
			{
				best = 	a[j] / b[j] + ( a[j] % b[j] != 0 );
				bestId = j; 
			}
		}
		result += (char) bestId + 'a';
		b[bestId]++;
	}

	int best =-1, bestId= -1; 
	for(int j =0; j < 26; j++ ) 
	{
		if ( a[j]==0) 
			continue;
		if ( ( a[j] / b[j] + ( a[j] % b[j] != 0 ) ) > best ) 
		{
			best = 	a[j] / b[j] + ( a[j] % b[j] != 0 );
			bestId = j; 
		}
	}
	cout << best << endl << result << endl;
}