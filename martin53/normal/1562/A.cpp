#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int l,r;
    cin>>l>>r;

    if(2*l>r)return r%l;
    return (r-1)/2;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<endl;
    }

    return 0;
}