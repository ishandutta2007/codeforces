#include <bits/stdc++.h>

using namespace std;
char v[1000006],rz[1000006];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j=0,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b;
    cin>>v;
    n=strlen(v);
    for(i=0;i+1<n-i-2;i+=2)
    {
        int fv[3];
        fv[0]=fv[1]=fv[2]=0;
        ++fv[v[i]-'a'];
        ++fv[v[i+1]-'a'];
        ++fv[v[n-i-1]-'a'];
        ++fv[v[n-i-2]-'a'];
        if(fv[0]>1)
            rz[i]=rz[n-i-1]='a';
        else if (fv[1]>1)
            rz[i]=rz[n-i-1]='b';
        else
            rz[i]=rz[n-i-1]='c';
    }
    if(i-1<=n-i-2)
    {
        rz[i]=v[i];
    }
    for(i=0;i<n;++i)
        if(rz[i])
            cout<<rz[i];
    return 0;
}