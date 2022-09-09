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
vi pred;
string s;
int i=0;
while ( cin>>s)
{
	i+=s.size()+1;
	if ( s[s.size()-1]=='.' || s[s.size()-1]=='?' || s[s.size()-1]=='!')
	{
		pred.pb (i-1);
		i=0;
	}
}
bool flag=true;
for ( int i=0; i<pred.size(); i++ )
	if ( pred[i]>n )
		flag=false;
if (!flag)
{
	printf ("Impossible");
	return;
}

int dp[10000];
dp[0]=1;
for (int i=1; i<pred.size(); i++)
{
	int sum=pred[i];
	int j;
	for ( j=i-1; j>=0 && sum+pred[j]+1<=n; j-- )
	{
		sum+=pred[j]+1;
		//cout<<sum<<endl;
	}
	if (j==-1 || sum+pred[j]+1<=n)
		dp[i]=1;
	else 
	dp[i]=dp[j]+1;
}

cout<<dp[pred.size()-1];
}