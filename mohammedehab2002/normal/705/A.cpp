#include <iostream>
#include <string.h>
using namespace std;
string s[]={"that I hate ","that I love "};
int main()
{
	int n;
	cin >> n;
	string ans="I hate ";
	n--;
	int a=n%2;
	while (n)
	{
		ans+=s[(n%2)==a];
		n--;
	}
	ans+="it";
	cout << ans;
}