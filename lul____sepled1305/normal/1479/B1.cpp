#include<bits/stdc++.h>
using namespace std;
int INF = 1e6;

int main()
{
    int n,i,ans = 0, fi = -1, se = -1;
    cin>>n;
    int a[n];
    bool f[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int counti = 0, lf = -1;
    for(i=0;i<n;i++)
    {
        if(a[i-1] == a[i])
            continue;
        if(a[i] == a[i+1])
        {
            ans += counti;
            if(counti > 1 || lf != a[i])
                ans += 2;
            else
                ans += 1;
            counti = 0;
            lf = a[i];
        }
        else
        {
            if(a[i] != lf)
                counti++;
            else
            {
                counti--;
                ans += 2;
            }
        }
    }
    ans += counti;
    cout<<ans;
    return 0;
}