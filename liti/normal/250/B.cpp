#include <iostream>
#include <string> 
#include <vector>
using namespace std;

vector<string> seperate(string s)
{
    vector<string> result;
    result.push_back("");
    for (int i = 0 ; i < s.length() ; ++i )
    {
	if (s[i] == ':')
	{
	if ( i != s.length() -1 && i != 0 )	    
	    result.push_back("");
       }else
	    result[result.size() -1] += s[i];
    }

    return result;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
	string s;
	cin >> s;
	if ( s == "::" )
	    cout << "0000:0000:0000:0000:0000:0000:0000:0000" << endl;
	else
	{
	    vector<string> result = seperate(s);
	    for(int i = 0 ; i < result.size() ; ++i)
	    {
		int t = 4 - result[i].length() ; 
		//cout << t << endl;
		int times;
		if ( t == 4 )
		    times = 8 - result.size() + 1;
		else
		    times = 1;
		//cout << times << endl;
		for(int j = 0; j < times; j++)
		{
		t = 4 - result[i].length();
		while(t--)
		    cout << '0';
		//cout << '/';
		cout << result[i];
		if ( i != result.size() - 1 )
		    cout << ':';
		if ( i == result.size() -1 && j != times - 1 )
		    cout << ':';
		}
	    }
	    cout << endl;
	}
    }
}