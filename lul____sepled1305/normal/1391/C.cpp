/** MAKOTOCHANNNNNNNNNNNN **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int n,i;
long long cur = 1, ff = 1;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>n;
    for(i=1;i<=n-1;i++)
    {
        cur*=i;
        cur%=MOD;
        ff*=2;
        ff%=MOD;
    }
    cur*=n;
    cur%=MOD;
    cout<<((cur-ff)+MOD)%MOD;
    return chtholly;
}

/**
    SORAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    is the best girl.
**/