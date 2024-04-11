
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long li;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve ();
int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int t=1;
    while (t--)
    solve();
    return 0;
}
//#define int li
int n;
ld x[200500];
int binsearch ( ld val )
{
    int l=0, r=n;
    while ( l+1<r )
    {
        int m=l+r; m/=2;
        if ( x[m]<=val )
            l=m;
        else 
            r=m;
    }
    return l;
}
vector <ld> answer;
int see ( ld d )
{
    int cur=0;
    vector <ld> ans;
    for ( int u=0; u<3; u++ )
    {
        int prev=cur;
        if ( cur<n )
        {
        ld z=x[cur]+2*d;
        int place=binsearch (z);
        cur=place+1;
        }
        ans.pb ( x[min(prev, n-1)]+d );
    }
    if ( cur<n )
        return 0;
    answer=ans;
    return 1;
}
void solve()
{
    cin>>n;
    for ( int i=0; i<n; i++ )
        cin>>x[i];
    sort (x, x+n);
    n=(unique(x, x+n)-x);
    if ( n==1 )
    {
        cout<<"0.0000000"<<endl;
        printf ("%.7Lf", x[0]);
        cout<<" 0.0000000 0.0000000";
        return;
    }
    if ( n==2 )
    {
        cout<<"0.0000000"<<endl;
        printf ("%.7Lf %.7Lf", x[0], x[1]);
        cout<<" 0.00000000";
        return;
    }
    ld l=0, r=x[n-1]-x[0]+1e-9;
    while ( l+1e-7<r )
    {
        ld m=(l+r)/2;
        int ans=see (m);
        if ( ans==1 )
            r=m;
        else 
            l=m;
    }
    printf ("%.7Lf\n%.7Lf %.7Lf %.7Lf", l, answer[0], answer[1], answer[2]);
}