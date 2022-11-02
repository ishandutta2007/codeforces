#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int n;
	cin >> n;

	bool sefr = false;
	if ( n == 0 ) 
	{
		n = 1;
		sefr = true;
	}
	string p[n];
	int l[n],r[n];
	if ( sefr == false )
	{
	for(int i = 0 ; i < n ; i++ ) 
		cin >> p[i] >> l[i] >> r[i];

	}
	else
	{
		p[0] = s;
		l[0] = 0;
		r[0] = s.size();
	}
	long long ans = 0;
	vector<string> result;
	for(int i = 0 ; i < s.size() ; i++ )
	{
		for(int j = 0 ; i + j < s.size() ; j++ ) 
		{
			string tmp = s.substr( i, j + 1 );

			bool good = false;
			for(int t = 0 ; t < n ; t++ )
			{
				int k;
				int pos = 0;
				int counter =0;
				int index = 0;
				while (index < p[t].size() && (int)p[t].find( tmp , index ) != -1 )
				{
					index = (int)p[t].find( tmp, index ) + 1;
					counter++;
				}
				if ( !( counter <= r[t] && counter >= l[t]) ) {
					good = false;
					break;
				}
				good = true;
			}
			if ( good ) 
			{
				bool check  =true;
				for(int m = 0 ; m < result.size() ; m++ )
					if ( result[m] == tmp ) 
					{
						check = false;
						break;
					}
				if ( check )
				{
		//			cout << tmp << endl;
					result.push_back( tmp ) ;
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}