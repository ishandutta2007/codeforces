#include <bits/stdc++.h>

using namespace std;
char v[100005];
int d[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,i,j,cnt=0;
    cin>>v;
    n=strlen(v);
    for(i=n-1;i>=0;--i)
    {
        if(v[i]=='0')
            d[i]=1+d[i+1];
        else
            ++cnt,d[i]=max(d[i+1],cnt);
    }
    for(i=0;i<=n-2;++i)
        if(d[i]==d[i+1]+1)
            cout<<0;
        else
            cout<<1;
    cout<<0;
    return 0;
}