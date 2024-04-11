/**Ithea is the master of binary search problem.**/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
int n,k,i;

bool check(int ss, int siz)
{
    int j,counti=0;
    bool odd = false, even = false;
    bool allow = true;
    for(j=0;j<n;j++)
    {
        if(allow && a[j]<=ss)
        {
            counti++;
            allow = false;
        }
        else if(!allow)
        {
            counti++;
            allow = true;
        }
    }
    if(counti>=siz)
        odd = true;
    allow = false;
    counti =0;
    for(j=0;j<n;j++)
    {
        if(allow && a[j]<=ss)
        {
            counti++;
            allow = false;
        }
        else if(!allow)
        {
            allow = true;
            counti++;
        }
    }
    if(counti>=siz)
        even = true;
    return odd | even;
}

int b_search(int mini, int maxi, int siz)
{
    while(mini<maxi)
    {
        int mid = mini + maxi >> 1;
        if(mid == mini)
        {
            if(check(mini,siz))
                maxi = mini;
            else
                mini = maxi;
        }
        else
        {
            if(check(mid,siz))
                maxi = mid;
            else
                mini = mid+1;
        }
    }
    return mini;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<b_search(0,1e9,k);
    return 0;
}