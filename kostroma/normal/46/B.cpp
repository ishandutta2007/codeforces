#include <stdio.h>
#include <set>
#include <vector>
#include <math.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
void prepare ()
{
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
#else 
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
}


int main( )
{
	int a[10], b[2000];
	int i;
	for (i=0; i<5; i++)
		cin>>a[i];
	int n;
	cin>>n;
	char w;
	w=getchar ();
	string q;
	string s[5];
	s[0]="S";
	s[1]="M";
	s[2]="L";
	s[3]="XL";
	s[4]="XXL";
	for (i=0; i<n; i++)
	{
		cin>>q;
		if (q=="S")
			b[i]=0;
		if (q=="M")
			b[i]=1;
		if (q=="L")
			b[i]=2;
		if (q=="XL")
			b[i]=3;
		if (q=="XXL")
			b[i]=4;
		w=getchar ();
	}
	for (i=0; i<n; i++)
	{
		if (a[b[i]]>0)
		{
			cout<<s[b[i]];
			printf ("\n");
			a[b[i]]--;
			continue;
		}
		if (b[i]<4 && a[b[i]+1]>0)
		{
			cout<<s[b[i]+1];
			printf ("\n");
			a[b[i]+1]--;
			continue;
		}
		if (b[i]>0 && a[b[i]-1]>0)
		{
			cout<<s[b[i]-1];
			printf ("\n");
			a[b[i]-1]--;
			continue;
		}
		if (b[i]<3 && a[b[i]+2]>0)
		{
			cout<<s[b[i]+2];
			printf ("\n");
			a[b[i]+2]--;
			continue;
		}
		if (b[i]>1 && a[b[i]-2]>0)
		{
			cout<<s[b[i]-2];
			printf ("\n");
			a[b[i]-2]--;
			continue;
		}
		if (b[i]>2 && a[b[i]-3]>0)
		{
			cout<<s[b[i]-3];
			printf ("\n");
			a[b[i]-3]--;
			continue;
		}
		if (b[i]<2 && a[b[i]+3]>0)
		{
			cout<<s[b[i]+3];
			printf ("\n");
			a[b[i]+3]--;
			continue;
		}
		if (b[i]>3 && a[b[i]-4]>0)
		{
			cout<<s[b[i]-4];
			printf ("\n");
			a[b[i]-4]--;
			continue;
		}
		if (b[i]<1 && a[b[i]+4]>0)
		{
			cout<<s[b[i]+4];
			printf ("\n");
			a[b[i]+4]--;
			continue;
		}
	}
	return 0;
}