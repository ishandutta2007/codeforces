#include <bits/stdc++.h>

using namespace std;
long long fv[1003][5];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j=0,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b,st,dr,mx=0,cur=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        mx=max(mx,a);
        s+=a;
    }
    if(s%2==1 || mx>s/2)
        cout<<"NO";
    else
    cout<<"YES";
    return 0;
}