/** Ithea best girl **/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

void solve()
{
    int n,i,m;
    cin>>n>>m;
    pii v[n];
    double unsorted = 1;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v[i] = {a,i};
    }
    sort(v,v+n);
    int maxi = -1;
    for(i=0;i<n;i++)
    {
        if(v[i].second != i)
            maxi = i;
    }

    for(i=0;i<m;i++)
    {
        int a;
        double b;
        cin>>a>>b;
        if(a > maxi)
            unsorted*=(1-b);
    }

    unsorted = 1-unsorted;
    double one = 1;
    if(maxi == -1)
        printf("%.10f\n",one);
    else
        printf("%.10f\n",unsorted);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}