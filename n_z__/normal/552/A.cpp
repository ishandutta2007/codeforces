#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(n--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        ans+=(abs(c-a)+1)*(abs(d-b)+1);
    }
    cout<<ans<<endl;
}