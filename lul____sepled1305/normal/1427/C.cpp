/**Ogiso Setsuna**/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,r,i,j,maxi = -1;
int dp[N];

struct trip
{
    int time,x,y;
};

trip cel[N];

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>r>>n;
    int pointer1 = 0, pointer2 =0;
    for(i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cel[i] = {a,b,c};
    }
    cel[0] = {0,1,1};
    dp[0] = 1;
    while(pointer2 < n)
    {
        pointer2++;
        while(cel[pointer1].time +1000 < cel[pointer2].time)
        {
            maxi = max(maxi,dp[pointer1]);
            pointer1++;
        }
        if(pointer1 >= 0)
            pointer1--;
        i = pointer2-1;
        while(i > pointer1)
        {
            if(cel[pointer2].time - cel[i].time >= abs(cel[pointer2].x - cel[i].x)+abs(cel[pointer2].y - cel[i].y) && dp[i] > 0)
                dp[pointer2] = max(dp[pointer2],dp[i]+1);
            i--;
        }
        if(maxi > 0)
            dp[pointer2] = max(dp[pointer2],maxi+1);
    }
    maxi = 0;
    for(i=0;i<=n;i++)
        maxi = max(maxi,dp[i]);
    cout<<maxi-1;
    return 0;
}