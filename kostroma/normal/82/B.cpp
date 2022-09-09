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
int n;
vector < int > pairs[100000];
vector <  int > sets[500];
map < vector <int>, vector <int> > m;
typedef map < vector <int>, vector <int> >::iterator it;
bool is[500];
void solve ()
{
        cin>>n;
		if ( n==2 )
		{
			int q;
			cin>>q;
			int w;
			cin>>w;
			cout<<"1 "<<w<<endl;
			cout<<q-1<<' ';
			q--;
			while ( q-- )
			{
				cin>>w;
				cout<<w<<" ";
			}
		}
        for ( int i=0; i<n*(n-1)/2; i++ )
        {
                int l;
                scanf ("%d", &l);
                for ( int j=0; j<l; j++ )
                {
                        int q; scanf ("%d", &q);
                        pairs[i].pb(q);
                        sets[q].pb ( i );
                        is[q]=true;
                }
        }
        int t=0;
        for ( int i=0; i<300; i++ )
                if ( is[i] )
                {
                        if ( m.find(sets[i])==m.end() )
                                m[sets[i]]=vi();
                        m[sets[i]].pb (i);
                }
        for ( it i=m.begin(); i!=m.end(); i++ )
        {
                printf ("%d ", (i->second).size());
                for ( int j=0; j<(i->second).size(); j++ )
                        printf ("%d ", (i->second)[j]);
                printf ("\n");
        }
}