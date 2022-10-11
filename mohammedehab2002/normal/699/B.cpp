#include <iostream>
#include <string.h>
#include <set>
using namespace std;
int r[1005],c[1005];
int main()
{
    int n,m,cnt=0;
    cin >> n >> m;
    char arr[n][m];
    for (int i=0;i<n;i++)
    {
    	for (int x=0;x<m;x++)
    	cin >> arr[i][x];
	}
	for (int i=0;i<n;i++)
    {
    	for (int x=0;x<m;x++)
    	{
    		if (arr[i][x]=='*')
    		r[i]++,c[x]++,cnt++;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		{
			if (r[i]+c[x]-1==cnt && arr[i][x]=='*')
			{
				cout << "YES\n" << i+1 << ' ' << x+1;
				return 0;
			}
			else if (r[i]+c[x]==cnt && arr[i][x]=='.')
			{
				cout << "YES\n" << i+1 << ' ' << x+1;
				return 0;
			}
		}
	}
	cout << "NO";
}