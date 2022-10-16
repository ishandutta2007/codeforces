#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001],b[100001],n;
bool check(int m)
{
    int k=n+m;
    k=k-(int)(k/4);
    int sa=0,sb=0;
    if(m>=k)sa=100*k;
    else {sa=100*m;for(int x=n;x>=n+m-k+1;x--)sa+=a[x];}
    if(n>=k)for(int x=n;x>=n-k+1;x--)sb+=b[x];
    else for(int x=1;x<=n;x++)sb+=b[x];
    return sa>=sb;
}
main () {
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int x=1;x<=n;x++)
        cin>>a[x];
        for(int x=1;x<=n;x++)
        cin>>b[x];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int l=0,r=3*n,m;
        while(l<r)
        {
            m=(l+r)/2;
            if(check(m))r=m;
            else l=m+1;
        }
        cout<<l<<endl;
    }
}