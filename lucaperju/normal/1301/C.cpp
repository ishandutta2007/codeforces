#include <bits/stdc++.h>
using namespace std;
char v[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,i,j,t,k,cur=0,cnt=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        long long rz=n*1LL*(n+1LL)/2LL;
        n=n-m;
        m=m+1;
        long long l=n/m;
        rz-=(l*1LL*(l+1LL)/2LL)*(m-n%m);
        rz-=((l+2LL)*1LL*(l+1LL)/2LL)*(n%m);
        cout<<rz<<'\n';
    }
    return 0;
}