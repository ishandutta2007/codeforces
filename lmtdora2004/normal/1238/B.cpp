#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100005];

signed main()
{
    int tests;
    cin>>tests;
    for(int test=1; test<=tests; test++)
    {
        int n, r;
        cin>>n>>r;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        a[0]=-1;
        sort(a+1, a+n+1);
        int need=0;
        for(int i=n; i>=1; i--)
        {
            if(a[i]==a[i-1]) continue;
            if(a[i]>need*r)
            {
                need++;
            }
            else
            {
                break;
            }
        }
        cout<<need<<endl;
    }
}