#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int ret=0;

    int n;
    cin>>n;

    for(int d=1;d<=9;d++)
    {
        long long val=d;

        while(val<=n)
        {
            ret++;
            val=val*10+d;
        }
    }

    return ret;
}

int main()
{
    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
        cout<<solve()<<endl;

    return 0;
}