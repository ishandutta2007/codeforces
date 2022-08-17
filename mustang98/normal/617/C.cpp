#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

ll F[2002], S[2002];

using namespace std;
ll dist(ll x1, ll y1, ll x2, ll y2)
{
    ll r = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    return r;
}
int main()
{
    ll n, x1,y1,x2,y2,x,y,r1,r2,R=1e18,max2=-5;
    //cout<<R;
    cin>>n>>x1>>y1>>x2>>y2;
    for (int i=0;i<n;i++)
    {
        cin>>x>>y;
        F[i]=dist(x,y,x1,y1);
        S[i]=dist(x,y,x2,y2);
        max2=max(max2,S[i]);
    }
    R=max2;
    for (int i=0;i<n;i++)
    {
        r1=F[i];
        r2=0;
        for (int j=0;j<n;j++)
        {
            if(F[j]<=r1) continue;
            r2=max(r2,S[j]);
        }
        R=min(R,r1+r2);
    }
    cout<<R;
    return 0;
}