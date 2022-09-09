#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
#define fin for (i=0; i<n; i++)
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef vector <int> vi;
const ld PI=3.14159265358979323846264338327950288419716939937510;
void prepare ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
}









int n, a[1000], k, s, b[1000];
int main ()
{
	prepare ();
	cin>>n>>k>>s;
	int i;
	for (i=0; i<s; i++)
		cin>>a[i];
	int q=s;
	int j;
	for (i=0; i<k; i++)
		b[i]=1;
	for (i=0; i<s; i++)
	{
			for (j=a[i]; j<a[i]+k; j++)
				b[j]=1;
	}
	for (i=1; i<=n; i++)
	{
		if (b[i]==0)
		{
			q++;
			for (j=i; j<i+k; j++)
				b[j]=1;
		}
	}
	cout<<q;
	return 0;
}