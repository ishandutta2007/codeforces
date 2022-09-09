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


int main ()
{
	prepare ();
	string s;
	cin>>s;
	int n=s.length();
	int i, t=0;
	for (i=0; i<n; i++)
	{
		if (t==0 && s[i]=='h')
		{
			t++;
			continue;	
		}
		if (t==1 && s[i]=='e')
			{
			t++;
			continue;	
		}
		if (t==2 && s[i]=='l')
			{
			t++;
			continue;	
		}
		if (t==3 && s[i]=='l')
			{
			t++;
			continue;	
		}
		if (t==4 && s[i]=='o')
			{
			t++;
			continue;	
		}
	}
	if (t==5)
		printf ("YES");
	else 
		printf ("NO");
	return 0;
}