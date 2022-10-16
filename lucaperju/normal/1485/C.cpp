#include <bits/stdc++.h>
using namespace std;
int sp[100005],v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long la,lb;
        cin>>la>>lb;
        long long cnt=0;
        for(long long x=1;x*x+x+x<=la;++x)
        {
            long long linf=x*x+x+x;
            long long lsup=la-la%x;
            lsup=min(lsup,lb*1LL*x+x);
            if(lsup>=linf)
                cnt+=((lsup-linf)/x+1);
        }
        cout<<cnt<<'\n';
    }
    return 0;
}