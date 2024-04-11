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
typedef pair <long long, long long> pi;
typedef vector <int> vi;
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
#endif
	int t=1;
	while (t--)
	solve ();
}
#define int li
int gcd (int q, int w)
{
	if (q<w)
		swap (q, w);
	while (w>0)
	{
		q%=w;
		swap (q, w);
	}
	return q;
}
int maxx, maxy, w;
pair <int, int> drob[200000];
map < pi, int > m;
void filldrob ()
{
	for (int i=1; i<max (maxx, maxy)+1; i++)
{
	int t=i;
	vi ob;
	int sum=1;
	while ( sum<=i )
	{
		ob.pb ((i/sum)%10);
		sum*=10;
	}
	int obr=ob[0];
	for (int j=1; j<ob.size(); j++)
		obr=obr*10+ob[j];
	int g=gcd (obr, i);
	i/=g; obr/=g;
	drob[t]=mp (i, obr);
	i=t;
	//cout<<t<<" "<<drob[t].first<<"/"<<drob[t].second<<endl;
}
}
int curans=0;
map < pi, int > mayx;
void add (int cury)
{
	pi cur=drob[cury];
	swap (cur.first, cur.second);
	if (mayx.find(cur)!=mayx.end())
		curans+=mayx[cur];
	//cout<<mayx[cur]<<endl;
	m[cur]++;
}
pi ans(-1,-1);
void solve ()
{
	m.clear();
	mayx.clear();
	ans.first=-1; ans.second=-1;
	curans=0;
	cin>>maxx>>maxy>>w;
	filldrob();
	int curx=maxx, cury=1;
	m[mp (1, 1)]++;
	for ( int i=1; i<=maxx; i++ )
	{
		mayx[drob[i]]++;
		if (drob[i]==mp (1LL, 1LL))
			curans++;
	}
	while ( curx>0 )
	{
		if (curans<w)
		{
			while ( curans<w && cury<maxy)
		{
			cury++;
			add (cury);
		}
		}
		if ( curans<w )
			break;
		int answer=curans;
		if (ans.first==-1)
			ans=mp (curx, cury);
		else 
			if ( curx*cury<ans.first*ans.second )
				ans=mp (curx, cury);
		mayx[drob[curx]]--;
		if ( m.find(drob[curx])!=m.end() )
		{
		curans-=m[drob[curx]];
		}
		if ( mayx[drob[curx]]==0 )
			mayx.erase(drob[curx]);
		//cout<<"curx = "<<curx<<"  cury = "<<cury<<" answer = "<<answer<<endl;
		curx--;
	}
	if (ans.first==-1)
		cout<<"-1"<<endl;
	else
	cout<<ans.first<<" "<<ans.second<<endl;
}