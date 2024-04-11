#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
using namespace std;
typedef long double ld;
void prepare ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
#endif
}

int a[5000], b[5000];
char w[2000][2000];
int main ()
{
	prepare ();
	int i, n, m, r;
	char q;
	 cin>>n>>m;
	int j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			cin>>q;
			w[i][j]=q;
			if (q=='*')
			{
				a[i]++;
				b[j]++;
			}
		}
	}
	long long s=0;
	for (i=0; i<n; i++)
		if (a[i]>1)
		for (j=0; j<m; j++)
			if (w[i][j]=='*' && b[j]>0)
			{
				s+=(a[i]-1)*(b[j]-1);
			}
	cout<<s;
return 0;
}