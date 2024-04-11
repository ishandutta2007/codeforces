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

string s[10050];
vector < string > str[20];
int main ()
{
	prepare ();
	int n;
	cin>>n;
	int i;
	int q=0;
	for (i=0; i<n; i++)
	{
		cin>>s[i];
		q+=s[i].length();
		str[s[i].length()].pb(s[i]);
	}
	q/=(n/2);
	char d;
	cin>>d;
	for (i=1; i<=10; i++)
	{
		sort ( str[i].begin(), str[i].end() );
		reverse (str[i].begin(), str[i].end());
	}
	for (i=0; i<n/2; i++)
	{
		string mi;
		int j;
		for (j=1; j<=10; j++)
		if (str[j].size()>0)
		{
		mi=str[j][str[j].size()-1];
		mi+=d;
		break;
		}
		int u=j;
		for (j=u+1; j<=10; j++)
		if (str[j].size()>0)
		{	
			string mu=str[j][str[j].size()-1];
			mu+=d;
			if (mu<mi)
			{
				u=j;
				mi=mu;
			}
		}
		str[u].pop_back();
		cout<<mi;
		mi=str[q-u][str[q-u].size()-1];
		cout<<mi<<endl;
		str[q-u].pop_back();
	}
	return 0;
}