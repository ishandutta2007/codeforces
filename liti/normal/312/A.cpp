#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int n;
	string tmp;
	getline(cin, tmp) ;

	n = atoi(tmp.c_str());
	for(int i =0 ;i < n ;i++ )
	{
		string s; 
		getline(cin, s);
		if ( s.size() >= 5 ) 
		{
			string s1 = "" , s2 = "";
			for(int j = s.size() - 5; j <= s.size() - 1 ; j++ )
				s2.push_back( s[j] ) ;
			for(int j = 0 ; j < 5 ; j++ ) 
				s1.push_back(s[j]);
			if (!( s1 == "miao." && s2 == "lala." )) 
			{
				if ( s1 == "miao." ) 
				{
					cout << "Rainbow\'s"  << endl;
					continue;
				}
				if ( s2 == "lala." ) 
				{
					cout << "Freda\'s" << endl;
					continue;
				}
			}
		}
	
			cout << "OMG>.< I don't know!" << endl;
	}
}