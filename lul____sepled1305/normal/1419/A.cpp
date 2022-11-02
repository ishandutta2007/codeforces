
/** Mion Best Girl **/
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
        int n,odd = 0, even = 0,i;
        string s;
        cin>>n>>s;
        if(n%2 == 1)
        {
            bool pass = false;
            for(i=0;i<n;i+=2)
            {
                int val = s[i]-'0';
                if(val%2 == 1)
                    pass = true;
            }
            cout<<2-pass<<endl;
        }
        else
        {
            bool pass = false;
            for(i=1;i<n;i+=2)
            {
                int val = s[i]-'0';
                if(val%2 == 0)
                    pass = true;
            }
            cout<<1+pass<<endl;
        }
    }
    return chtholly;
}