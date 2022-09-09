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
int n;
string typ[102];
string name[102];
int be[102];
void solve ()
{
cin>>n;
int i;
for (i=0; i<n; i++)
{
	cin>>name[i]>>typ[i];
}
int r=0;
bool rat=false, child=false, man=false;
while (r<n)
{
	for ( int j=0; j<n; j++ )
		if ( be[j]==0 )
		{
			//cout<<typ[j]<<endl;
			if ( man==true && typ[j][0]=='c'&& typ[j][1]=='a')
			{
				cout<<name[j]<<endl;
				r++;
				be[j]=1;
				return;
			}
			if ( child==true && typ[j][0]=='m')
			{
				cout<<name[j]<<endl;
				r++;
				be[j]=1;
				continue;
			}
			if ( rat==true && ( typ[j][0]=='w' || (typ[j][0]=='c' && typ[j][1]=='h' ) ) )
			{
				cout<<name[j]<<endl;
				r++;
				be[j]=1;
				continue;
			}
			if ( typ[j]=="rat" )
			{
				cout<<name[j]<<endl;
				r++;
				be[j]=1;
				continue;
			}
		}
	if ( rat==false )
		rat=true;
		else 
		if ( child==false )
			child=true;
			else 
			if (man==false)
				man=true;
}
}