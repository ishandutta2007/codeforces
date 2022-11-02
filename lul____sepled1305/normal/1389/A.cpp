/**Neunzehn**/
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
        long long l,r;
        cin>>l>>r;
        if(r>=2*l)
        {
            cout<<l<<" "<<2*l<<"\n";
        }
        else
            cout<<"-1 -1\n";
    }
    return chtholly;
}

/**
    OWARI NI SHIYOU.
    -- Epic Jihad chorus start --
**/