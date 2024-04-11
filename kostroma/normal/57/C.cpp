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


li binpow (li q, li w)
{
	if (w==0)
		return 1;
	if (w==1)
		return q;
	if (w%2==0)
	{
	li u=binpow(q, w/2)%p;
	return (u*u)%p;
	}
	li u=binpow(q, w-1)%p;
	return (u*q)%p;
}
int main ()
{
	prepare ();
	li n;
	cin>>n;
	li i, s=1;
	for (i=2*n-1; i>n; i--)
	{
	s*=i;
	s%=p;
	}
	li u=1;
	for (i=2; i<n; i++)
	{
		u*=i;
		u%=p;
	}
	li ans=binpow(u, p-2);
	ans*=s;
	ans%=p;
	ans*=2;
	ans-=n;
	ans=ans%p;
	cout<<ans;
	return 0;
}