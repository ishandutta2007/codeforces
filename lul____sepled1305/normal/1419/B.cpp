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
        long long n, ans = 0, cur = 1;
        cin>>n;
        while(n>0)
        {
            long long stair = (cur*(cur+1))/2;
            if(stair > n)
                break;
            n -= stair;
            cur*=2;
            cur+=1;
            ans++;
        }
        cout<<ans<<endl;
    }
    return chtholly;
}