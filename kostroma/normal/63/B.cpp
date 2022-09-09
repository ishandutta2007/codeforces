#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <int> vi;
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
#endif
	solve ();
}
int n, k, a[200];
int b[200];
void solve ()
{
cin>>n>>k;
for (int j=0; j<n; j++)
{
	cin>>a[j];
	b[a[j]]++;
}
if ( b[k]==n )
{
	cout<<"0";
	return;
}
for (int i=1; i<=10000; i++)
{
	for (int j=k; j>1; j--)
	{
		if ( b[j-1]>0 )
		{
			b[j-1]--;
			b[j]++;
		}
	}
	if (b[k]==n)
	{
		cout<<i;
		return;
	}
}
}