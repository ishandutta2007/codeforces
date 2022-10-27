#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int p=998244353,inv2=(p+1)/2;
int qp(int x,int n=p-2)
{
    int r=1;
    while(n)
    {
        if(n&1)r=r*x%p;
        x=x*x%p,n>>=1;
    }
    return r;
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1);
        int cnt=0;
        for(int x=1;x<=n;x++)
        cin>>a[x],cnt+=a[x];
        int ccnt=0;
        for(int x=1;x<=n-cnt;x++)
        if(a[x]==1)ccnt++;
        int ans=0;
        for(int x=1;x<=ccnt;x++)
        ans=(ans+n*(n-1)%p*inv2%p*qp(x)%p*qp(x)%p)%p;
        cout<<ans<<endl;
    }
}