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
        int n,x,i;
        cin>>n>>x;
        int rate[n];
        bool all = true;
        int instant = 0;
        for(i=0;i<n;i++)
            cin>>rate[i];
        for(i=0;i<n;i++)
        {
            if(rate[i] == x)
                instant++;
            else
                all = false;
        }

        if(all)
            cout<<0<<endl;
        else
        {
            if(instant == 0)
            {
                int sum = 0;
                for(i=0;i<n;i++)
                    sum+=rate[i];
                if(sum == x*n)
                    cout<<"1\n";
                else
                    cout<<"2\n";
            }
            else
            {
                cout<<"1\n";
            }
        }
    }
    return chtholly;
}