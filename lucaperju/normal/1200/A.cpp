#include <bits/stdc++.h>

using namespace std;
int v[10];
int main()
{
    ios_base::sync_with_stdio(0);
    long long k=0,t,i,j=0,cnt=0,n,is,js,ib,jb,s=0,cur=0,q;
    cin>>n;
    for(j=1;j<=n;++j)
    {
        char a;
        cin>>a;
        if(a=='L')
        {
            for(i=0;v[i]==1;++i);
            v[i]=1;
        }
        else
        if(a=='R')
        {
            for(i=9;v[i]==1;--i);
            v[i]=1;
        }
        else
            v[a-'0']=0;
    }
    for(i=0;i<=9;++i)
        cout<<v[i];
}