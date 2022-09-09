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

int main ()
{
	prepare ();
	int i, n, r;
	 cin>>n;
	int q[5];
	q[0]=0; q[1]=0; q[2]=0; q[3]=0; q[4]=0;
	for (i=0; i<n; i++)
	{
		cin>>r;
		q[r]++;
	}
	if (q[2]>q[1])
		swap (q[1], q[2]);
	if (q[3]>q[1])
		swap (q[1], q[3]);
	cout<<( q[2]+q[3]);
return 0;
}