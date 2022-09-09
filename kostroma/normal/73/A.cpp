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
int x, y, z, k;
int ans=0;
void check ( int q, int w )
{
        int e=k-q-w;
        if ( q>=x || w>=y || e>=z || q<0 || w<0 || e<0)
                return;
        if ( ans<(q+1)*(w+1)*(e+1) )
        {
                ans=(q+1)*(w+1)*(e+1);
                //cout<<q<<" "<<w<<" "<<e<<endl;
        }
               
}
void solve ()
{
        int a[3];
        cin>>a[0]>>a[1]>>a[2]>>k;
        sort (a, a+3);
        x=a[0]; y=a[1]; z=a[2];
        int p=k/3;
        if ( k>=x+y+z-3 )
        {
                cout<<x*y*z;
                return;
        }
        check (x-1, y-1);
        check (x-1, p );
        check (x-1, p+1);
        check ( x-1, (k-x+1)/2 );
        check ( p, p );
        check ( p+1, p );
        check ( p, p+1 );
        check ( p-1, p+1 );
        cout<<ans;
}