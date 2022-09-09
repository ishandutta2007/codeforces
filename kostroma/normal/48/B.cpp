#include <stdio.h>
#include <math.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>
using namespace std;
typedef vector <int> vi;
typedef long long li;
typedef long double ld;
#define fin for (i=0; i<n; i++)
void prepare ()
{
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
#else 
#endif
}


int main ()
{
	prepare ();
	int n, m, a, b;
	int q[100][100];
	cin>>n>>m;
	int i, j;
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			cin>>q[i][j];
	cin>>a>>b;
	int s=n*m;
	for (i=0; i<=n-a; i++)
		for (j=0; j<=m-b; j++)
		{
			int r=0;
			for (int k=i; k<i+a; k++)
				for (int l=j; l<j+b; l++)
					if (q[k][l]==1)
						r++;
			if (r<s)
				s=r;
		}
		for (i=0; i<=n-b; i++)
		for (j=0; j<=m-a; j++)
		{
			int r=0;
			for (int k=i; k<i+b; k++)
				for (int l=j; l<j+a; l++)
					if (q[k][l]==1)
						r++;
			if (r<s)
				s=r;
		}
		cout<<s;
return 0;
}