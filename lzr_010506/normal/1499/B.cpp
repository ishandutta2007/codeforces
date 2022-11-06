#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string a;
		cin >> a;
		int len = a.size();
		int i;
		int f = 1;
		for(i=0; i<len; i++)
		{
			if(i < len-1) if(a[i] == '1' && a[i] == a[i+1]) f = 0;
			if(i < len - 1 && a[i] == '0' && a[i] == a[i+1] && f == 0)
			{
				printf("no\n");
				goto L1;
			}
		}
		printf("yes\n");
		L1:;
	}
	return 0;
}