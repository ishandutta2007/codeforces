#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int arr[s.size()],m,i,a,b;
	arr[0]=0;
	for (i=0;i<s.size()-1;i++)
	arr[i+1]=arr[i]+(s[i]==s[i+1]);
	cin >> m;
	for (i=0;i<m;i++)
	{
		cin >> a >> b;
		cout << arr[b-1]-arr[a-1] << endl;
	}
}