
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
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int t=1;
    while (t--)
    solve();
    return 0;
}
//#define int li
int n, a[1000500], b[1000500];
int key[1000500];
int real[1000500];
int e[1000500];
const int inf=1<<30;
int binsearch ( int val )
{
    int l=0, r=n;
    while ( l+1<r )
    {
        int m=l+r; m/=2;
        if ( e[m]>=val )
            l=m;
        else 
            r=m;
    }
    return r;
}
void solve()
{
    scanf ("%d", &n);
    for ( int i=0; i<n; i++ )
    {
        scanf ("%d", &a[i]);
        key[a[i]]=i;
    }
    for ( int i=0; i<n; i++ )
    {
        scanf ("%d", &b[i]);
        real[i]=key[b[i]];
    }
    e[0]=inf;
    for ( int i=1; i<=n; i++ )
        e[i]=-inf;
    e[1]=real[0];
    for ( int i=1; i<n; i++ )
    {
        int place=binsearch( real[i] );
        e[place]=real[i];
        //cout<<place<<' '<<real[i]<<endl;
    }
    int ans=n;
    for ( int i=1; i<=n; i++ )
        if ( e[i]==-inf )
        {
            ans=i-1;
            break;
        }
    cout<<ans;
}