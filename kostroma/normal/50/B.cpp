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
li a[200];
int main()
{
	prepare ();
char s[200000];
gets (s);
int n=strlen (s);
int i;
for (i=0; i<n; i++)
a[s[i]]++;
li q=0;
for (i=0; i<200; i++)
q+=a[i]*a[i];
cout<<q;
return 0;
}