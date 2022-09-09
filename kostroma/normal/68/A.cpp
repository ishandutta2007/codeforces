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
#define int li
int p[4];
int ans=0;
int prove ( int x )
{
	int answer=x%p[0];
	answer%=p[1];
	answer%=p[2];
	answer%=p[3];
	if (answer==x)
		return 1;
	return 0;
}
void solve ()
{
	int  a, b;
	cin>>p[0]>>p[1]>>p[2]>>p[3]>>a>>b;
	for (int j=a; j<=b; j++)
	{
	int cur=0;
	for (int i=0; i<24; i++)
	{
		cur+=prove (j);
		next_permutation(p, p+4);
	}
	if (cur>=7)
		ans++;
	}
	cout<<ans;
}