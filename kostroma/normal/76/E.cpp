#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long li;
typedef pair<li, li> pli;
typedef long double ld;
#define mp make_pair
#define pb push_back
void solve();

int main(){
#ifdef DEBUG
	freopen("input", "r", stdin);
        //freopen("output","w", stdout);
#endif
        solve();
	return 0;
}
#define int li
int n;
int x[100500];
int y[100500];
void solve(){
    cin>>n;
    for ( int i=0; i<n; i++ )
        cin>>x[i]>>y[i];
    int sumx=0, sumy=0, kvx=0, kvy=0;
    for  (int i=0; i<n; i++)
    {
        sumx+=x[i]; sumy+=y[i];
        kvx+=x[i]*x[i]; kvy+=y[i]*y[i];
    }
    int ans=(n-1)*(kvx+kvy);
    for ( int i=0; i<n; i++ )
    {
        ans-=x[i]*(sumx-x[i]);
        ans-=y[i]*(sumy-y[i]);
    }
    cout<<ans;
}