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
typedef pair <li, li> pi;
typedef vector <li, li> vli;
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
map <string, int > m;
void solve ()
{
        m.clear();
        cin>>n;
        m["void"]=0;
		m["errtype"]=-1;
        while (n--)
        {
                string q;
                cin>>q;
                if ( q=="typedef" )
                {
                        string s;
                        cin>>s;
                        int a=0, b=0;
                        int j=0;
                        while ( j<s.length() && s[j]=='&' )
                        {
                                j++;
                                a++;
                        }
                        j=s.length()-1;
                        while ( j>=0 && s[j]=='*' )
                        {
                                j--;
                                b++;
                        }
                        string good;
                        for ( int i=0; i<s.length(); i++ )
                                if ( s[i]!='&' && s[i]!='*' )
                                        good.pb (s[i]);
                        if ( m.find(good)==m.end() )
                        {
                                cin>>s;
								m[s]=-1;
                                continue;
                        }
                        int cur=m[good];
                        cin>>s;
                        if ( cur==-1 )
                        {
                        m[s]=-1;
                        continue;
                        }
                        cur+=b-a;
                        if ( cur<0 )
                        {
                                m[s]=-1;
                                continue;
                        }
                        m[s]=cur;
                }
                else 
                {
                        string s;
                        cin>>s;
                        int a=0, b=0;
                        int j=0;
                        while ( j<s.length() && s[j]=='&' )
                        {
                                j++;
                                a++;
                        }
                        j=s.length()-1;
                        while ( j>=0 && s[j]=='*' )
                        {
                                j--;
                                b++;
                        }
                        string good;
                        for ( int i=0; i<s.length(); i++ )
                                if ( s[i]!='&' && s[i]!='*' )
                                        good.pb (s[i]);
                        if ( m.find(good)==m.end() )
                        {
                                cout<<"errtype"<<endl;
                                continue;
                        }
                        int cur=m[good];
                        if (cur==-1)
                                cout<<"errtype"<<endl;
                        else 
                        {
                                cur+=b-a;
                                if (cur<0)
                                {
                                        cout<<"errtype"<<endl;
                                        continue;
                                }
                                cout<<"void";
                                for ( int i=0; i<cur; i++ )
                                        cout<<"*";
                                cout<<endl;
                        }
                }
        }
}