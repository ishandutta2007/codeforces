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
int n, k;
vector <pair < char, int > > good[300];
string s;
int dp[200][300][30];
bool may[200][300][30];
void solve ()
{
		for ( int i=0; i<200; i++ )
			for ( int j=0; j<300; j++ )
				for ( int l=0; l<30; l++ )
					dp[i][j][l]=-(1<<30);
        cin>>s>>k>>n;
        getchar ();
        for ( int i=0; i<n; i++ )
        {
                char c, t;
                int r;
                cin>>c;
                getchar ();
                cin>>t;
                cin>>r;
                good[c-'a'].pb ( mp ( t, r ) );
                getchar ();
                //cout<<good[i].first.first<<" "<<good[i].first.second<<" "<<good[i].second<<endl;
        }
        for ( int i='a'; i<='z'; i++ )
                if ( s[0]==i )
                   {
					   may[0][0][i-'a']=true;
					   dp[0][0][i-'a']=0;
					}
                else 
				{
                        may[0][1][i-'a']=true;
						dp[0][1][i-'a']=0;
				}
        for ( int i=0; i<s.length()-1; i++ )
                for ( int num=0; num<=k; num++ )
                for ( int j='a'; j<='z'; j++ )
                {
                        if ( !may[i][num][j-'a'] )
                                continue;
                        int cur=dp[i][num][j-'a'];
                        bool be[30];
                        memset ( be, false, sizeof (be) );
                        for ( int l=0; l<good[j-'a'].size(); l++ )
                                be[(good[j-'a'][l].first)-'a']=true;
                        for ( int l='a'; l<='z'; l++ )
                                if ( !be[l-'a'] )
                        {
                                if ( s[i+1]==l )
                                {
                                        dp[i+1][num][l-'a']=max (cur, dp[i+1][num][l-'a']);
                                        may[i+1][num][l-'a']=true;
                                }
                                else 
                                {
                                        dp[i+1][num+1][l-'a']=max (cur, dp[i+1][num+1][l-'a']);
                                        may[i+1][num+1][l-'a']=true;
                                }
                        }
                        for ( int l=0; l<good[j-'a'].size(); l++ )
                        {
                                char next=good[j-'a'][l].first;
                                int add=good[j-'a'][l].second;
                                if ( s[i+1]==next )
                                {
                                dp[i+1][num][next-'a']=max (cur+add, dp[i+1][num][next-'a']);
                                may[i+1][num][next-'a']=true;
                                }
                                else 
                                {
                                dp[i+1][num+1][next-'a']=max (cur+add, dp[i+1][num+1][next-'a']);
                                may[i+1][num+1][next-'a']=true;
                                }
                        }
                }
        int mx=-(1<<30);
        for ( int num=0; num<=k; num++ )
                for ( int j='a'; j<='z'; j++ )
                        if ( may[s.length()-1][num][j-'a'] && mx<dp[s.length()-1][num][j-'a'] )
                        {
                                mx=dp[s.length()-1][num][j-'a'];
                        }
        cout<<mx;
}