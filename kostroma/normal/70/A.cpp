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
//#define int li

void solve ()
{
int n;
cin>>n;
int ans=1;
for (int i=2; i<=n; i++)
{
	ans*=3;
	ans%=1000003;
}
cout<<ans;
}