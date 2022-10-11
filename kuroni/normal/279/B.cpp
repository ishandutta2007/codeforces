#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,i=0,a[100000],ans=0,tmp=0,sum=0,cur=-1;
next(){sum -= a[i];i++;tmp--;}
add(){cur++;tmp++;sum+=a[cur];ans=max(ans,tmp);}
main()
{
    cin>>n;
    for (cin>>q;i<n;i++) cin>>a[i];
    i=0;
    while (i<n)
    {
        if ((sum+a[cur+1]<=q)&&(cur<n-1)) add(); else next();
    }
    cout<<ans;
}