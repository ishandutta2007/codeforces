#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int>p;
main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        int y;
        cin>>y;
        y-=x;
        p.push(y);
        ans+=p.top()-y;
        p.pop();
        p.push(y);
    }
    cout<<ans<<endl;;
}