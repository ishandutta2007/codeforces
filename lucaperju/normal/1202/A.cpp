#include <bits/stdc++.h>

using namespace std;
char a[200005],b[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long k,t,i,j=0,cnt=1,n,m,is,js,ib,jb,s=0,mx=0,cur=0,q;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int na=strlen(a);
        int nb=strlen(b);
        cur=0;
        for(i=nb-1;i>=0;--i)
        {
            ++cur;
            if(b[i]=='1')
                break;
        }
        int cur1=0;
        for(i=na-cur;i>=0;--i)
        {
            ++cur1;
            if(a[i]=='1')
                break;
        }
        cout<<cur1-1<<'\n';
    }
    return 0;
}