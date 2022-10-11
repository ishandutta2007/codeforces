#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i=0,x,c=0;
	string a;
	cin >> n;
	pair <string,int> s[n];
	while (i<n)
	{
		cin >> a;
		for (x=0;x<c;x++)
		{
			if (s[x].first==a)
			{
				s[x].second++;
				cout << a << s[x].second << endl;
				goto failed;
			}
		}
		cout << "OK\n";
		s[c].first=a;
		c++;
		s[c].second=0;
		failed: i++;
	}
}