#include <iostream>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int l1=0,l2=0;
	for(int i = 0 ; i < s1.length() ; i++) 
	{
		if ( s1[i] == '1' ) 
			l1++;
	}
	for(int i = 0; i < s2.length() ; i++ )
	{
		if ( s2[i] == '1' )
			l2++;
	}
	if ( l1 + ( !( l1 % 2 == 0 ) ) >= l2 ) 
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}