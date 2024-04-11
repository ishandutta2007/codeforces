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
#endif
	solve ();
}
int n;
int a[100000];
set <int> povt;
int prove (int k, int cur, int byk, int cor)
{
int one=k%10, two=(k/10)%10, three=(k/100)%10, four=(k/1000)%10;
int cone=cur%10, ctwo=(cur/10)%10, cthree=(cur/100)%10, cfour=(cur/1000)%10;
int z=0;
if ( one==cone )
z++;
if ( two==ctwo )
z++;
if ( three==cthree )
z++;
if ( four==cfour )
z++;
if (z!=byk)
return 0;
z=0;
if (one==ctwo || one==cthree || one==cfour)
z++;
if (two==cone || two==cthree || two==cfour)
z++;
if (three==ctwo || three==cone || three==cfour)
z++;
if (four==ctwo || four==cthree || four==cone)
z++;
if (z!=cor)
return 0;
return 1;
}
void solve ()
{
int z=0;
for (int i=100; i<10000; i++)
{
int one=i%10, two=(i/10)%10, three=(i/100)%10, four=(i/1000)%10;
povt.clear();
povt.insert (one); povt.insert (two); povt.insert (three); povt.insert (four);
if (povt.size()==4)
{
	a[i]=1;
	z++;
}
}
cin>>n;
for (int j=0; j<n; j++)
{
int cur, byk, cor;
cin>>cur>>byk>>cor;
for ( int i=100; i<10000; i++ )
if ( a[i]==1 && prove (i, cur, byk, cor)==0 )
{
a[i]=0;
z--;
}
if (z==0)
{
printf ("Incorrect data");
return;
}
}
if (z>1)
{
	printf ("Need more data");
	return;
}
if (z==1)
{
	for (int i=100; i<10000; i++)
		if (a[i]==1)
		{
			if ( i<1000 )
			cout<<"0";
			cout<<i;
			return;
		}
}
}