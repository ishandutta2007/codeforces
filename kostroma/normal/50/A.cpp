#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;
void prepare ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#else
#endif
}
int main()
{
	prepare ();
int n, m;
cin>>n>>m;
int s=0;
if (n%2==0)
{
cout<<(n/2*m);
return 0;
}
if (m%2==0)
{
	cout<<(m/2*n);
	return 0;
}
cout<<((n-1)/2*m+m/2);
return 0;
}