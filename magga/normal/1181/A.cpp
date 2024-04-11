#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int x,y,z,answer;cin>>x>>y>>z;
    if(x%z+y%z>=z)
    {
        answer=x/z+y/z+1;
        cout<<answer<<" ";
        if((z-x%z)<(z-y%z))
        {
            cout<<z-x%z<<endl;
        }
        else
        {
            cout<<z-y%z<<endl;
        }
    }
    else
    {
        answer=x/z+y/z;
        cout<<answer<<" ";
        cout<<0<<endl;
    }
}
int main()
{
       solve();
}