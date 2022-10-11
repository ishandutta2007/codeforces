#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char x,y;
	string s;
	int n,tmp,i,j,pos,arr[26];
	cin >> tmp >> n >> s;
	for (i=0;i<26;i++)
	arr[i]=i;
	for (i=0;i<n;i++)
	{
		cin >> x >> y;
		for (j=0;j<26;j++)
		{
			if (arr[j]==x-97)
			{
				arr[j]=y-97;
				pos=j;
				goto out;
			}
		}
		out: for (j=0;j<26;j++)
		{
			if (arr[j]==y-97 && pos!=j)
			{
				arr[j]=x-97;
				goto out2;
			}
		}
		out2: int t;
	}
	for (i=0;i<s.size();i++)
	cout << (char)(arr[s[i]-97]+97);
}