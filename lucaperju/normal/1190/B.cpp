#include <bits/stdc++.h>

using namespace std;
long long v[100005];
int main()
{
    long long n,m,i,j,a,b,c,cnt=0,k,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=2;i<=n;++i)
    {
        if(v[i]==v[i-1])
            ++cnt;
        if(i>=3 && v[i]==v[i-1] && v[i-2]==v[i]-1 || v[i]==v[i-1] && v[i]==0)
        {
            cout<<"cslnb";
            return 0;
        }
    }
    if(cnt>=2)
    {
        cout<<"cslnb";
        return 0;
    }
    for(i=1;i<=n;++i)
        s+=v[i];
    s=s-(n-1)*1LL*n/2LL;
    if(s%2LL==1)
        cout<<"sjfnb";
    else
        cout<<"cslnb";
    return 0;
}