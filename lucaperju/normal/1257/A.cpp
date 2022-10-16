#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,x,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>a>>b;
        if(a>b)
            swap(a,b);
        a=b-a;
        cout<<min(a+x,n-1)<<'\n';
    }
    return 0;
}