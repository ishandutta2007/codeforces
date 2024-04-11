#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
#endif
        int t=1;
        while (t--)
                solve ();
        return 0;
}
//caution: is int really int?
#define int li
int a, b, c;
vector < pair <li, li> > fact;
int pow (int q, int w, int mod)
{
	if (w==0)
		return 1;
	if (w%2)
		return (q*pow(q, w-1, mod))%mod;
	int u=pow (q, w/2, mod);
	return (u*u)%mod;
}
int pow1 (int q, int w)
{
	if (w==0)
		return 1;
	if (w%2)
		return q*pow1(q, w-1);
	int u=pow1 (q, w/2);
	return u*u;
}
int gcd (int q, int w)
{
	if (q<0)
		q=-q;
	if (w<0)
		w=-w;
	if (q<w)
		swap (q, w);
	while (w>0)
	{
		q%=w;
		swap (q, w);
	}
	return q;
}
void solve ()
{
	cin>>a>>b>>c;
	if ( a==0 )
	{
		if ( c%b==0 )
		{
			cout<<"0 "<<-c/b;
		}
		else
			cout<<"-1";
		return;
	}
	int g=gcd (a, b);
	if ( c%g )
	{
		cout<<"-1";
		return;
	}
	else 
	{
		a/=g; b/=g; c/=g;
	}
	int z=a;
	if (z<0)
		z=-z;
	for (int i=2; i*i<=z; i++)
		if (z%i==0)
		{
			pli cur=mp (i, 0);
			while (z%i==0)
			{
				z/=i;
				cur.second++;
			}
			fact.pb (cur);
		}
	if (z>1)
		fact.pb ( mp (z, 1) );
	int pr=1;
	for (int i=0; i<fact.size(); i++)
		pr*=( pow1(fact[i].first, fact[i].second)-pow1 (fact[i].first, fact[i].second-1) );
	z=pow ( b, pr-1, a );
	z=-(z*c);
	z%=a;
	//cout<<"z = "<<z<<endl;
	//cout<<"mod =  "<<(z*b+c)%a<<endl;
	if ( (z*b+c)%a==0 )
	{
		int h=-c-b*z; h/=a;
		cout<<h<<' '<<z;
	}
	else
		cout<<"-1";
}