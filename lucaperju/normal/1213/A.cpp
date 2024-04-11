#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,k=0,s=0,cnt=0,m,t;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(a&1)
            ++cnt;
        else
            ++s;
    }
    cout<<min(cnt,s);
    return 0;
}