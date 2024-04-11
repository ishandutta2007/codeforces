#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
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
//#define int li
int H, T, R, n, m, num;
vector < pair <pi, pi> > pere;
int d[700][700];
int timer=0;
void bfs ( int h, int t )
{
	d[h][t]=0;
	queue < pi > q;
	q.push( mp (h, t) );
	while ( !q.empty() )
	{
		//cout<<timer++<<endl;
		pi cur=q.front();
		//cout<<cur.first<<' '<<cur.second<<endl;
		q.pop();
		for ( int i=0; i<num; i++ )
		{
			pi add=pere[i].first;
			pi next=mp ( cur.first+add.first, cur.second+add.second);
			if ( pere[i].second.first<=cur.first && pere[i].second.second<=cur.second && next.first>=0 && next.second>=0 && next.first+next.second<=R && d[next.first][next.second]==-1 )
			{
				d[next.first][next.second]=d[cur.first][cur.second]+1;
				q.push(next);
				//cout<<next.first<<"  "<<next.second<<endl;
			}
		}
	}
}
bool be[700][700];
int color[700][700];
bool dfs ( int h, int t )
{
	//cout<<h<<' '<<t<<endl;
	be[h][t]=true;
	color[h][t]=1;
	for ( int i=0; i<num; i++ )
		{
			pi add=pere[i].first;
			pi next=mp ( h+add.first, t+add.second);
			if ( pere[i].second.first<=h && pere[i].second.second<=t && next.first>=0 && next.second>=0 && next.first+next.second<=R )
			{
				
				if ( !be[next.first][next.second] )
				{
					bool f=dfs (next.first, next.second);
					if (f)
						return true;
				}
				else 
				{
					//cout<<next.first<<' '<<next.second<<endl;
					if ( color[next.first][next.second] )
						return true;
				}
			}
		}
	color[h][t]=0;
	return false;
}
int answer[700][700];
int dfs1 (int h, int t)
{
	if ( answer[h][t]!=-1 )
		return answer[h][t];
	int ans=1;
	for (int i=0; i<num; i++)
	{
		pi add=pere[i].first;
		pi next=mp ( h+add.first, t+add.second );
		if ( pere[i].second.first<=h && pere[i].second.second<=t && next.first>=0 && next.second>=0 && next.first+next.second<=R)
			ans=max ( ans, dfs1(next.first, next.second)+1 );
	}
	//cout<<h<<' '<<t<<"   "<<ans<<endl;
	return answer[h][t]=ans;
}
void solve ()
{
	cin>>H>>T>>R;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		int q, w;
		cin>>q>>w;
		q-=i;
		pere.pb ( mp (mp (q, w), mp (i, 0)) );
	}
	cin>>m;
	for ( int i=1; i<=m; i++ )
	{
		int q, w;
		cin>>q>>w;
		w-=i;
		pere.pb ( mp(mp (q, w), mp (0, i)) );
	}
	sort (pere.begin(), pere.end());
	pere.resize( unique (pere.begin(), pere.end())-pere.begin() );
	num=pere.size();
	/*for (int i=0; i<num; i++)
		cout<<pere[i].first<<' '<<pere[i].second<<endl;*/
	memset (d, -1, sizeof d);
	bfs (H, T);
	if ( d[0][0]!=-1 )
	{
		cout<<"Ivan\n";
		cout<<d[0][0];
		return;
	}
	bool f=dfs (H, T);
	if (f)
	{
		cout<<"Draw";
		return;
	}
	memset (be, false, sizeof be);
	memset (answer, -1, sizeof answer);
	int z=dfs1(H, T);
	cout<<"Zmey\n";
	cout<<z;
}