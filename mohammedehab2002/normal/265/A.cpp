#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int i,x=0;
    string s,t;
    cin >> s >> t;
    for (i=0;i<t.size();i++)
    {
    	if (s[x]==t[i])
    	x++;
	}
	cout << x+1;
}