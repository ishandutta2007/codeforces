#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n,k,x,i;
long long pr,su,ans = 0;
long long a[N];
long long pref[N];
long long suf[N];

int main()
{
    cin>>n>>k>>x;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        su = su | a[n-1-i];
        pr = pr | a[i];
        pref[i] = pr;
        suf[n-1-i] = su;
    }
    for(i=0;i<n;i++)
    {
        long long ss = k;
        while(ss--)
        {
            a[i]*=x;
        }
        long long here = a[i];
        if(i!=0)
            here = here | pref[i-1];
        if(i!=n-1)
            here = here | suf[i+1];
        ans = max(ans,here);
    }
    cout<<ans;
}