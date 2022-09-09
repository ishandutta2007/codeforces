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
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <int> vi;
const li p=1000000007;
const ld PI=3.14159265358979323846264338327950288419716939937510;
void prepare ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
}



int a[100500], b[100500];
int main ()
{
	prepare ();
	int n;
	cin>>n;
	int i;
	for (i=0; i<n; i++)
	{
		cin>>a[i];
		a[i]=a[i]-min (i, n-1-i);
		if (a[i]>=1)
		b[a[i]]++;
	}
	int c=b[1];
	for (i=2; i<=100000; i++)
	if (c<b[i])
		c=b[i];
	cout<<(n-c);
	return 0;
}