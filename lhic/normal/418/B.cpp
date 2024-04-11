#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

struct fr
{
    ll x,k;
    int m;
};


bool cmp(fr a,fr b)
{
    if (a.k<b.k)
        return true;
    else
        return false;
}

fr arr[1000];

int n,m;
ll b;

ll dp[5000000];

ll dp2[5000000];




int main()
{
    cin>>n>>m>>b;
    for (int i=0;i<n;++i)
    {
        int mm;
        cin>>arr[i].x>>arr[i].k>>mm;
        arr[i].m=0;
        for (int j=0;j<mm;++j)
        {
            int a;
            cin>>a;
            arr[i].m|=1<<(a-1);
        }
    }

    sort(arr,arr+n,cmp);

    for (int i=0;i<1<<m;++i)
        dp[i]=-1;
    for (int i=0;i<1<<m;++i)
        dp2[i]=-1;

    dp[0]=0;
    dp2[0]=0;


    for (int i=0;i<n;++i)
    {
        ll dop=b*arr[i].k;
        for (int j=1;j<1<<m;++j)
        {
            ll xx=arr[i].x + dp2[j ^ (j & arr[i].m)];
            //cout<<i<<" "<<j<<" "<<xx<<"\n";
            if (xx == arr[i].x-1)
                continue;
            if (dp[j] > dop + xx  || dp[j]==-1)
                dp[j] = dop + xx;
            if (dp2[j] > xx || dp2[j]==-1)
                dp2[j] = xx;

        }
    }


    cout<<dp[(1<<m)-1];
    return 0;
}