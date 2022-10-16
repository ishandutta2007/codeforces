#include <bits/stdc++.h>
using namespace std;
long long get (long long a, long long b)
{
    long long cnt=0;
    if(b==1)
        return 1000000000;
    while(a)
    {
        a/=b;
        ++cnt;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,m,k=0;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long mn=get(a,b);
        ++b;
        int cntc=1;
        while(1)
        {
            if(cntc>mn)
               break;
            mn=min(mn,cntc+get(a,b));
            ++b;
            ++cntc;
        }
        cout<<mn<<'\n';
    }
    return 0;
}