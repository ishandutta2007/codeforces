#include <iostream>
using namespace std;
int arr[2];
int main()
{
	int n;
	string s;
	cin >> n >> s;
	for (int i=1;i<n;i++)
	{
		if (s[i]!=s[i-1])
		arr[s[i]=='S']++;
	}
	if (arr[0]>arr[1])
	printf("YES");
	else
	printf("NO");
}