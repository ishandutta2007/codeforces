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
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int n,m,i,j,ans = 0;
        cin>>n>>m;
        string a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<=m-2;i++)
        {
            if(a[n-1].at(i)!='R')
                ans++;
        }
        for(i=0;i<=n-2;i++)
        {
            if(a[i].at(m-1)!='D')
                ans++;
        }
        cout<<ans<<endl;
    }
    return chtholly;
}

/**
    SORAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    is the best girl.
**/