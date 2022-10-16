#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i;
    int a;
    cin>>n;
    long long s=0;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        s+=a;
    }
    cout<<s;
}