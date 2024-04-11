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
int n, d, x, y;
pi vec[500];
int win[1000][1000];
int rec ( int a, int b )
{
    if ( win[a][b]!=0 )
        return win[a][b];
    if ( (a-201)*(a-201)+(b-201)*(b-201)>d*d )
    {
        win[a][b]=1;
        return 1;
    }
    for ( int i=0; i<n; i++ )
        if ( rec( a+vec[i].first, b+vec[i].second )==-1 )
        {
            win[a][b]=1;
           return 1;
        }
     win[a][b]=-1;
    return -1;
}
void solve ()
{
    cin>>x>>y>>n>>d;
    memset (win, 0, sizeof (win));
    for (int i=0; i<n; i++)
        cin>>vec[i].first>>vec[i].second;
    int ans=rec (x+201, y+201);
    if ( ans==1 )
        printf ("Anton");
    if (ans==-1)
        printf ("Dasha");
}