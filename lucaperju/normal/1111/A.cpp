#include <bits/stdc++.h>

using namespace std;
char a[1005],b[1005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long i,j,s=0,cur=0,pz,m,ok=0;
    cin>>a>>b;
    int n=strlen(a);
    m=strlen(b);
    if(n!=m)
    {
        cout<<"No";
        return 0;
    }
    for(i=0;i<n;++i)
    {
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='u' || a[i]=='o')
            a[i]='a';
        else
            a[i]='b';
        if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='u' || b[i]=='o')
            b[i]='a';
        else
            b[i]='b';
        if(a[i]!=b[i])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}