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
//#define int li
int n, a, b, c;
map <string , int> m;
// 0 Anka, 1 Chapay, 2 Cleo, 3 Troll, 4 Dracul, 5 Snowy 6 Hexadecimal
vector <int> sym[10];
void ins ( string s, string q )
{
	sym[m[s]].pb(m[q]);
}
int fun ( int q, int w, int e )
{
	int t[3];
	t[0]=a/q;
	t[1]=b/w;
	t[2]=c/e;
	sort (t, t+3);
	//cout<<t[2]-t[0]<<endl;
	return t[2]-t[0];
}
void solve ()
{
	cin>>n;
	m["Anka"]=0;
	m["Chapay"]=1;
	m["Cleo"]=2;
	m["Troll"]=3;
	m["Dracul"]=4;
	m["Snowy"]=5;
	m["Hexadecimal"]=6;
	for ( int i=0; i<n; i++ )
	{
		string s, q;
		cin>>s;
		cin>>q; cin>>q;
		//cout<<s<<" "<<q<<endl;
		ins (s, q);
	}
	cin>>a>>b>>c;
	int ans=(1<<30);
	int mest[10];
	int kol[5];
	for ( mest[0]=0; mest[0]<3; mest[0]++ )
			for ( mest[1]=0; mest[1]<3; mest[1]++ )
				for ( mest[2]=0; mest[2]<3; mest[2]++ )
					for ( mest[3]=0; mest[3]<3; mest[3]++ )
						for ( mest[4]=0; mest[4]<3; mest[4]++ )
							for ( mest[5]=0; mest[5]<3; mest[5]++ )
								for ( mest[6]=0; mest[6]<3; mest[6]++ )
								{
									memset (kol, 0, sizeof (kol));
									for ( int u=0; u<7; u++ )
										kol[mest[u]]++;
									if ( kol[0]==0 || kol[1]==0 || kol[2]==0 )
										continue;
									int curans=fun ( kol[0], kol[1], kol[2]);
									//cout<<kol[0]<<" "<<kol[1]<<" "<<kol[2]<<" "<<curans<<endl;
									if ( curans<ans )
										ans=curans;
									for ( int l=0; l<7; l++ )
									{
										for ( int u=0; u<sym[l].size(); u++ )
										{
											int cur=sym[l][u];
											if ( mest[cur]==mest[l] )
												curans++;
										}
									}
									
								}
			int answer=0;
	for ( mest[0]=0; mest[0]<3; mest[0]++ )
			for ( mest[1]=0; mest[1]<3; mest[1]++ )
				for ( mest[2]=0; mest[2]<3; mest[2]++ )
					for ( mest[3]=0; mest[3]<3; mest[3]++ )
						for ( mest[4]=0; mest[4]<3; mest[4]++ )
							for ( mest[5]=0; mest[5]<3; mest[5]++ )
								for ( mest[6]=0; mest[6]<3; mest[6]++ )
								{
									memset (kol, 0, sizeof (kol));
									for ( int u=0; u<7; u++ )
										kol[mest[u]]++;
									if ( kol[0]==0 || kol[1]==0 || kol[2]==0 )
										continue;
									ld curans=fun ( kol[0], kol[1], kol[2] );
									if ( curans==ans )
									{
									int cura=0;
									for ( int l=0; l<7; l++ )
									{
										for ( int u=0; u<sym[l].size(); u++ )
										{
											int cur=sym[l][u];
											if ( mest[cur]==mest[l] )
												cura++;
										}
									}
									
										if ( cura>answer )
											answer=cura;
									}
								}
			cout<<ans<<" "<<answer;
}